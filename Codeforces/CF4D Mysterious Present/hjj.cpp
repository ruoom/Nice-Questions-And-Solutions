#include <cstdio>
#include <algorithm>
int f[5005],g[5005];
struct info{int x,y,id;}a[5005];
void print(int x){
	if(x==1)return;
	print(g[x]);
	printf("%d ",a[x].id);
}
bool cmp(const info &a,const info &b){
	return a.x<b.x||(a.x==b.x && a.y<b.y);
}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stpout);
	int n,h,w,m=0,ans=0,ans1;
	scanf("%d%d%d",&n,&h,&w);
	for(int i=1,x,y;i<=n;++i){
		scanf("%d %d",&x,&y);
		if(x<=h||y<=w)continue;
		a[++m].x=x;a[m].y=y;a[m].id=i;
	}
	if(m==0){printf("0");return 0;}
	a[++m].x=h;a[m].y=w;
	std::sort(a+1,a+m+1,cmp);
	for(int i=2;i<=m;++i){
		for(int j=1;j<i;++j)
			if(a[j].x<a[i].x && a[j].y<a[i].y && f[i]<f[j]+1){f[i]=f[j]+1;g[i]=j;}
		if(f[i]>ans){ans=f[i];ans1=i;}
	}
	printf("%d\n",ans);
	print(ans1);
	return 0;
}
