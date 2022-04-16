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
void ____() {   //srand(time(0));
    cin.tie(0)->sync_with_stdio(0);  //cout.tie(0);
#ifdef LOCAL
    #include "Debug.h"
    bool uno = freopen("..\\in.txt", "r", stdin);
    bool exp = freopen("..\\out.txt", "w", stdout);
#endif
}
template<class T> istream& operator>>(istream& is, pair<T, T>& v) { is >> v.first >> v.second;       return is; }
template<class T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i;        return is; }
template<class T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
//-------------------------------------------------------------------------------------


signed main() {
    ____();

    int n, q;
    cin >> n >> q;
    map<int, int> mp;
    int ans = n;
    mp[n] = 1;
    for (int i = 0; i < q; ++i) {
        int l, r, k;
        cin >> l >> r >> k;
        auto it = mp.lower_bound(l);
        while (it != mp.end()) {
            int L = it->second, R = it->first;
            if (r < L) {
                break;
            }
            ans = ans - (min(r, R) - max(l, L) + 1);
            mp.erase(it++);
            if (R > r) {
                mp[R] = r + 1;
            }
            if (L < l) {
                mp[l - 1] = L;
            }
        }
        if (k == 2) {
            mp[r] = l;
            ans += r - l + 1;
        }
        cout << ans << endl;
    }


    return 0;
} 
