#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

vector<pair<pair<int, int>, int> > c;
int dp[5111];
int prej[5111];

int main(){
	int n, a1, b1, sk;
	scanf("%d%d%d", &n, &a1, &b1);
	sk = n;
	for(int i = 0; i < n; i++){
		prej[i] = -1;
		int a, b;
		scanf("%d%d", &a, &b);
		if(a <= a1 || b <= b1) {sk--; continue;}
		c.push_back(make_pair(make_pair(a, b), i));
	}

	n = sk;
	//for(int i = 0; i < n; i++) printf("%d %d %d\n", c[i].first.first, c[i].first.second, c[i].second);

	sort(c.begin(), c.end());

	for(int i = 0; i < n; i++){
		int tren = 0;
		int pr = -1;
		for(int j = 0; j < i; j++){
			if(c[i].first.first > c[j].first.first && c[i].first.second > c[j].first.second){
				if(dp[j] > tren){
					tren = dp[j];
					pr = j;
				}
			}
		}
		dp[i] = tren + 1;
		if(pr > -1) prej[i] = pr;
	}

	int ans = 0, ind = -1;
	for(int i = 0; i < n; i++){
		if(dp[i] > ans){
			ans = dp[i];
			ind = i;
		}
	}
	
	printf("%d\n", ans);
	if(ans == 0)  return 0;

	stack<int> s;



	while(prej[ind] != -1){
		s.push(c[ind].second);
		ind = prej[ind];
	}

	printf("%d ", c[ind].second + 1);

	while(!s.empty()){
		printf("%d ", s.top() + 1);
		s.pop();
	}
	return 0;
}
