#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 100005;

int p[N];
const int mod = 1e9 + 7;

signed main()
{
        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                for(int i =1;  i <= n ; ++i){
                         int x ;
                         cin >> x;
                         p[x] = i;
                }
                int ans = 1;
                int l , r;
                l = r = p[0];

                for(int i = 1; i < n; ++i){
                        if(p[i] > l && p[i] < r)
                             ans *= (r - l + 1) - i;
                        ans %= mod;
                        l = min(l, p[i]);
                        r = max(r, p[i]);
                }
                cout << ans << endl;
        }
                                    
	return 0;
}
