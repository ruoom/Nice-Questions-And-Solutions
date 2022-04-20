#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb emplace_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vct;
typedef pair<int,int> pii;
const int N=1E6+10;
const int inf=1<<30;
ll read()
{
    ll a=0;
    char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar(45),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int head[N],nex[N<<1],to[N<<1];
int son[N],dep[N];
int q[N],*pos[N],ans[N];
void add(int u,int v)
{
    static int cnt=0;
    nex[++cnt]=head[u];
    head[u]=cnt;
    to[cnt]=v;
}
void dfs1(int x,int f)
{
    for(int i=head[x];i;i=nex[i])
    {
        int t=to[i];
        if(t==f)continue;
        dfs1(t,x);
        if(dep[t]>dep[son[x]])son[x]=t;
    }
    dep[x]=dep[son[x]]+1;
}
void dfs2(int x,int f)
{
    static int *now=q;
    ++*(pos[x]=++now);
    int y=son[x];
    if(!y)return;
    dfs2(y,x);
    if(pos[y][ans[y]]>1)ans[x]=ans[y]+1;
    for(int j=head[x];j;j=nex[j])
    {
        int t=to[j];
        if(t==f||t==y)continue;
        dfs2(t,x);
        for(int i=1;i<=dep[t];++i)
        {
            pos[x][i]+=pos[t][i-1];
            if(pos[x][i]>pos[x][ans[x]]||pos[x][i]==pos[x][ans[x]]&&i<ans[x])ans[x]=i;
        }
    }
}
int main()
{
    int n=read();
    for(int i=n;--i;)
    {
        int u=read(),v=read();
        add(u,v);
        add(v,u);
    }
    dfs1(1,0);
    dfs2(1,0);
    for(int i=1;i<=n;++i)write(ans[i],'\n');
}
