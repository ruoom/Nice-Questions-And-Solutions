//problem:CF1242B
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define lob lower_bound
#define upb upper_bound
#define fst first
#define scd second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

inline int read(){
	int f=1,x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline ll readll(){
	ll f=1,x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=1e5+5;
struct EDGE{int nxt,to;}edge[MAXN<<1];
int head[MAXN],tot;
inline void add_edge(int u,int v){edge[++tot].nxt=head[u];edge[tot].to=v;head[u]=tot;}
int n,m,s[MAXN],cnt;
bool vis[MAXN],t_vis[MAXN];
int main() {
	n=read();m=read();
	for(int i=1,u,v;i<=m;++i)u=read(),v=read(),add_edge(u,v),add_edge(v,u);
	for(int i=1;i<=n;++i)s[++cnt]=i;tot=0;
	for(int st=1;st<=n;++st)if(!vis[st]){
		++tot;
		queue<int>q;q.push(st);
		while(!q.empty()){
			int u=q.front();q.pop();vis[u]=1;
			for(int i=head[u];i;i=edge[i].nxt)t_vis[edge[i].to]=1;
			for(int i=1;i<=cnt;++i){
				if(vis[s[i]]){
					assert(s[i]==st);
					s[i--]=s[cnt--];
				}
				else if(!t_vis[s[i]]){
					q.push(s[i]);
					s[i--]=s[cnt--];
				}
				else t_vis[s[i]]=0;
			}
		}
	}
	cout<<tot-1<<endl;
	return 0;
}
