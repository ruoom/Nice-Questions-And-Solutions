#include<bits/stdc++.h>
using namespace std;
const int Maxn=1e5;

inline int read()
{
    char ch=getchar();
    int f=1,x=0;
    while(ch>'9' || ch<'0')
    {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

struct Node
{
    int to,nxt,id;
} Edge[Maxn*2+5];
int tot,Head[Maxn+5];

inline void Addedge(int x,int y,int z)
{
    Edge[++tot]=(Node){y,Head[x],z};
    Head[x]=tot;
}

int n,m,ans[Maxn+5];
int fa[Maxn+5],siz[Maxn+5],dep[Maxn+5];
int son[Maxn+5],top[Maxn+5],val[Maxn+5];

inline void dfs1(int x,int f,int d)
{
    fa[x]=f,siz[x]=1,dep[x]=d;
    for(register int i=Head[x];i;i=Edge[i].nxt)
    {
        int y=Edge[i].to;
        if(y==f) continue;
        dfs1(y,x,d+1);
        siz[x]+=siz[y];
        if(siz[y]>siz[son[x]]) son[x]=y;
    }
}
inline void dfs2(int x,int t)
{
    top[x]=t;
    for(register int i=Head[x];i;i=Edge[i].nxt)
    {
        int y=Edge[i].to;
        if(y==fa[x] || y==son[x]) continue;
        dfs2(y,y);
    }
    if(son[x]) dfs2(son[x],t);
}
inline void dfs3(int x)
{
    for(register int i=Head[x];i;i=Edge[i].nxt)
    {
        int y=Edge[i].to;
        if(y==fa[x]) continue;
        dfs3(y),val[x]+=val[y],ans[Edge[i].id]=val[y];
    }
}
inline int LCA(int x,int y)
{
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        x=fa[top[x]];
    }
    return dep[x]<dep[y]?x:y;
}

int main()
{
    n=read();
    for(register int i=1;i<n;++i)
    {
        int a=read(),b=read();
        Addedge(a,b,i),Addedge(b,a,i);
    }
    dfs1(1,0,0),dfs2(1,1);
    m=read();
    while(m--)
    {
        int a=read(),b=read();
        val[a]++,val[b]++,val[LCA(a,b)]-=2;
    }
    dfs3(1);
    for(register int i=1;i<n;++i)
        printf("%d ",ans[i]);
    return 0;
}
