#include<bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long
#define debug(x) cout << #x << " is " << x << endl
#define mkp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define INF 2e18
using namespace std;

const int mod = 1000000007;
int cnta[200005],cntb[200005];
int an[200005],bn[200005];
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		int a,b,k;
		cin >> a >> b >> k;
		for(int i = 0;i<=a;++i)
			cnta[i] = 0;
		for(int i= 0;i<=b;++i)
			cntb[i] = 0;
		for(int i =0 ;i<=k;++i)
			an[i]=bn[i]=0;
		for(int i =0;i<k;++i){
			cin >> an[i];
			cnta[an[i]]++;
		}
		for(int i =0;i<k;++i){
			cin >> bn[i];
			cntb[bn[i]]++;
		}
		int ans =0;
		for(int i =0;i<k;++i){
			ans += (k-cnta[an[i]]-cntb[bn[i]])+1; //容斥原理
		}
		cout << ans/2 << endl;
	}
	
	
	return 0;
}
