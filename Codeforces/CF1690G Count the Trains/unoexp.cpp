#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define LL
//#define ll long long
#define ull unsigned long long
#define endl '\n'
#define mkp(a,b) make_pair(a,b)
#define pii pair<int,int> 
#define umap unordered_map
#define all(x) x.begin(),x.end()
#define inf 2e18
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
#ifdef LL
#define int long long
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

int a[N];

signed main() {
    ____();
    

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        set<int> s;
        auto find = [&](int x) {
            return *prev(s.upper_bound(x));
        };
        for (int i = 1; i <= n; ++i) {
            if (i == 1 || a[i] < a[find(i - 1)])
                s.emplace(i);
        }
        for (int j = 0; j < m; ++j) {
            int k, x;
            cin >> k >> x;
            int g = min(a[find(k)], a[k] - x);
            if (g != a[find(k)]) {
                s.emplace(k);
                auto l = s.upper_bound(k);
                for (auto it = l; it != s.end(); ) {
                    if (a[find(*it)] < g)break;
                    it = s.erase(it);
                }
            }
            cout << s.size() << " ";
            a[k] -= x;
        }
        cout << endl;
    }

    
    return 0;
}
