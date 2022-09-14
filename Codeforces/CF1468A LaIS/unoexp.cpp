#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define int long long
// #define ll long long
#define ull unsigned long long
#define endl '\n'
#define mkp(a,b) make_pair(a,b)
#define pii pair<int,int> 
#define all(x) x.begin(),x.end()
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

template <typename T>
struct Fenwick {
    const int n;
    std::vector<T> a;
    Fenwick(int n) : n(n), a(n) {}
    void add(int x, T v) {
        for (int i = x; i < n; i += i & -i) {
            a[i] = max(a[i], v);
        }
    }
    T sum(int x) {
        T ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans = max(ans, a[i]);
        }
        return ans;
    }
    T sum(int l, int r) {
        return sum(r) - sum(l);
    }
};
//-------------------------------------------------------------------------------------



signed main() {
    ____();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pii> a(n);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i - 1].first;
            a[i - 1].second = i;
        }
        
        vector<int> dp(n + 1);
        Fenwick<int> f(n + 2);
        stack<pii> s;
        vector<int> lst(n + 1);
        for (int i = 1; i <= n; ++i) {
            while (!s.empty() && s.top().first < a[i - 1].first) {
                s.pop();
            }
            if (!s.empty()) {
                lst[i] = s.top().second;
            }
            s.emplace(a[i - 1]);
        }
        sort(all(a));
        for (int i = 0; i < n; ++i) {
            auto [x, p] = a[i];
            dp[p] = f.sum(p) + 1;
            if (lst[p])
                dp[p] = max(dp[p], f.sum(lst[p] - 1) + 2);
            f.add(p, dp[p]);
        }

        int ans = *max_element(all(dp));
        cout << ans << endl;
    }



    return 0;
}
