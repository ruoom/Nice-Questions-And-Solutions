#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
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

const int N = 500005;

int a[N];

signed main() {
    ____();

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] -= i;
    }
    vector<int> d;
    d.push_back(0);
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        d.push_back(x);
    }
    d.push_back(n + 1);
    a[0] = -inf, a[n + 1] = inf;
    int m = d.size();
    bool ok = 1;
    for (int i = 1; i < m; ++i) {
        if (a[d[i]] < a[d[i - 1]]) {
            ok = 0; break;
        }
    }
    if (!ok) {
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    for (int i = 1; i < m; ++i) {
        int l = d[i - 1], r = d[i];
        
        vector<int> f;
        for (int j = l + 1; j <= r - 1; ++j) {
            if (a[j] < a[l] || a[j] > a[r]) continue;
            auto it = upper_bound(all(f), a[j]);
            if (it == f.end()) f.push_back(a[j]);
            else *it = a[j];
        }
        ans += r - l - 1 - f.size();
    }
    cout << ans << endl;

    return 0;
}
