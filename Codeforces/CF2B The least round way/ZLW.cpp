#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
//dp[i][j][0]:到第i行j列最少有几个2
//dp[i][j][1]:到第i行j列最少有几个5
int dp[maxn][maxn][2];
int main(){
	int n;
	scanf("%d",&n);
	int pos=-1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int x;
			scanf("%d",&x);
			if(!x){
				pos=i;
				continue;
			}
			//记录该数含有多少个2和5 
			int y=x;
			while(!(x&1)){
				dp[i][j][0]++;
				x>>=1;
			}
			while(y%5==0){
				dp[i][j][1]++;
				y/=5;
			}
		}
	}
	//处理第一行与第一列 
	for(int i=1;i<n;i++){
		dp[i][0][0]+=dp[i-1][0][0];
		dp[i][0][1]+=dp[i-1][0][1];
		
		dp[0][i][0]+=dp[0][i-1][0];
		dp[0][i][1]+=dp[0][i-1][1];
	}
	//第i行j列可以从第(i-1)行j列(向下走)或第i行(j-1)列(向右走)转移 
	//显然应从2或5最少的一种状态转移 
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			dp[i][j][0]+=min(dp[i-1][j][0],dp[i][j-1][0]);
			dp[i][j][1]+=min(dp[i-1][j][1],dp[i][j-1][1]);
		}
	}
	string ans;
	//最终答案应取2最少还是5最少 
	int res=dp[n-1][n-1][0]>dp[n-1][n-1][1]?1:0;
	//特判含有0的情况 
	if(pos!=-1 && dp[n-1][n-1][res]>0){
		printf("1\n");
		for(int i=0;i<pos;i++) printf("D");
		for(int i=1;i<n;i++) printf("R");
		for(int i=pos;i<n-1;i++) printf("D");
		return 0;
	}
	int i=n-1,j=n-1;
	//只需要处理较少一种的路径 
	//逆推 
	while(1){
		if(dp[i-1][j][res]<dp[i][j-1][res]){
			i--;
			ans+="D";
		}else{
			j--;
			ans+="R";
		}
		//走到第一行或第一列 
		if(i==0){
			for(int x=0;x<j;x++) ans+="R";
			break;
		}
		if(j==0){
			for(int x=0;x<i;x++) ans+="D";
			break;
		}
	}//
	printf("%d\n",dp[n-1][n-1][res]);
	for(int i=ans.size()-1;i>-1;i--) printf("%c",ans[i]);
	return 0;
}
