#include <bits/stdc++.h>
#define N 100005
#define getchar nc
using namespace std;
int n,m;
struct Link_cut_tree{
	int top,c[N][2],fa[N],size[N];
	inline void pushup(int x)
	{
		size[x]=size[c[x][0]]+size[c[x][1]]+1;
	}
	inline bool isroot(int x)
	{
		return c[fa[x]][0]!=x&&c[fa[x]][1]!=x;
	}
	inline void rotate(int x)
	{
		int y=fa[x],z=fa[y],l,r;
		if(c[y][0]==x)
			l=0;
		else
			l=1;
		r=l^1;
		if(!isroot(y))
			if(c[z][0]==y)
				c[z][0]=x;
			else
				c[z][1]=x;
		fa[x]=z;
		fa[y]=x;
		fa[c[x][r]]=y;
		c[y][l]=c[x][r];
		c[x][r]=y;
		pushup(y);
		pushup(x);
	}
	inline void splay(int x)
	{
		while(!isroot(x))
		{
			int y=fa[x],z=fa[y];
			if(!isroot(y))
				if((c[y][0]==x)^(c[z][0]==y))
					rotate(x);
				else
					rotate(y);
			rotate(x);
		}
	}
	inline void access(int x)
	{
		for(register int t=0;x;t=x,x=fa[x])
		{
			splay(x);
			c[x][1]=t;
			pushup(x);
		}
	}
	inline int find(int x)
	{
		access(x);
		splay(x);
		while(c[x][0])
			x=c[x][0];
		return x;
	}
	inline void cut(int x)
	{
		access(x);
		splay(x);
		fa[c[x][0]]=0;
		c[x][0]=0;
		pushup(x);
	}
}T;
inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf; 
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++; 
}
inline int read()
{
    register int x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
    return x*f;
}
inline void write(register int x)
{
    if(!x)putchar('0');if(x<0)x=-x,putchar('-');
    static int sta[20];register int tot=0;
    while(x)sta[tot++]=x%10,x/=10;
    while(tot)putchar(sta[--tot]+48);
}
int main()
{
	n=read(),m=read();
	for(register int i=1;i<=n;++i)
	{
		int x=read();
		if(i+x<=n)
			T.fa[i]=i+x;
	}
	while(m--)
	{
		int opt=read();
		if(opt==1)
		{
			int x=read();
			write(T.find(x)),putchar(' '),write(T.size[x]),puts("");
		}
		else
		{
			int x=read(),y=read();
			T.cut(x);
			if(x+y<=n)
				T.fa[x]=x+y;
		}
	}
	return 0;
}
