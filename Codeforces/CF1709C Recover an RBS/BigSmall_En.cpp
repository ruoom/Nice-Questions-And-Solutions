#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int N=200005;
char s[N];int n;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);n=strlen(s+1);
		int cnt=0,qry=0;
		for(int i=1;i<=n;++i){
			if(s[i]=='(')++cnt;
			else if(s[i]==')')--cnt;
			else ++qry;
			
			if(cnt+qry==1)cnt=1,qry=0;
		}
		if(abs(cnt)==qry)puts("YES");
		else puts("NO");
	}
	return 0;
}
