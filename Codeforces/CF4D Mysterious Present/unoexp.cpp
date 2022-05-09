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
void ____() {   srand(time(0));
    cin.tie(0)->sync_with_stdio(0);  //cout.tie(0);
#ifdef LOCAL
    bool uno = freopen("..\\in.txt", "r", stdin);
    bool exp = freopen("..\\out.txt", "w", stdout);
#endif
}
template<class T> istream& operator>>(istream& is, pair<T, T>& v) { is >> v.first >> v.second;       return is; }
template<class T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i;        return is; }
template<class T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << endl;return os; }
//-------------------------------------------------------------------------------------

int dp[5005], f[5005];

signed main() {
    ____();


    int n, w, h;
    cin >> n >> w >> h;
    vector<pair<pii, int> > a;
    for (int i = 1; i <= n; ++i) {
        int u, v;
        cin >> u >> v;
        if (u > w && v > h) {
            a.push_back(mkp(mkp(u, v), i));
        }
    }
    
    n = a.size();
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    int ed = 0;
    sort(all(a));
    dp[0] = -1;
    fill(dp, dp + 5005, -1);
    for (int i = 1;i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[j].first.first < a[i].first.first
                && a[j].first.second < a[i].first.second) {
                if (f[i] < f[j] + 1) {
                    f[i] = f[j] + 1;
                    dp[i] = j;
                }
            }
        }
        if (f[i] > ans) {
            ans = f[i];
            ed = i;
        }
    }
    stack<int> s;
    while (ed != -1){
        s.push(a[ed].second);
        ed = dp[ed];
    }
    cout << s.size() << endl;
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }



    
    return 0;
}
