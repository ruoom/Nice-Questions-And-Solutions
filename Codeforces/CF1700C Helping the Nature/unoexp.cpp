#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define mkp(a,b) make_pair(a,b)
#define pii pair<int,int> 
#define umap unordered_map
#define all(x) x.begin(),x.end()
#define Sum(a) (accumulate (all(a), 0ll))
#define inf 2e18
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
void ____() {
    srand(time(0));
    cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    bool uno = freopen("..\\in.txt", "r", stdin);
    bool exp = freopen("..\\out.txt", "w", stdout);
#endif
}
template<class T> istream& operator>>(istream& is, pair<T, T>& v) { is >> v.first >> v.second;       return is; }
template<class T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i;        return is; }
template<class T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << endl; return os; }
//-------------------------------------------------------------------------------------

const int N = 300005;
const int mod = 998244353;

signed main() {
    ____();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> diff(n);
        cin >> a;
        diff[0] = a[0];
        for (int i = 1; i < n; ++i) {
            diff[i] = a[i] - a[i - 1];
        }
        int ans = 0;
        debug(diff);
        for (int i = 1; i < n; ++i) {
            ans += abs(diff[i]);
            if (diff[i] < 0) {
                diff[0] += diff[i];
            }
        }
        ans += abs(diff[0]);
        cout << ans << endl;
    }


    return 0;
}
