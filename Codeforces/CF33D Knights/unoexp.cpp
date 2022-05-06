///////////////////////
// 　　　　　／＞　 フ 
// 　　　　| 　_　 _| 
//  　　　／`ミ _x 彡 
// 　 　 /　　　 　 | 
// 　　 /　  ヽ　　 ? 
// ／￣|　　 |　|　| 
// | (￣ヽ＿_ヽ_)_) 
// ＼二つ 
///////////////////////
//#pragma GCC optimize(2)
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
    #include "Debug.h"
    bool uno = freopen("..\\in.txt", "r", stdin);
    bool exp = freopen("..\\out.txt", "w", stdout);
#endif
}
template<class T> istream& operator>>(istream& is, pair<T, T>& v) { is >> v.first >> v.second;       return is; }
template<class T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i;        return is; }
template<class T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << endl;return os; }
//-------------------------------------------------------------------------------------

int dist(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

bitset<1005> a[1005];

signed main() {
    ____();

    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> kx(n), ky(n);
    vector<int> cx(m), cy(m), r(m);
    for (int i = 0; i < n;++i) {
        cin >> kx[i] >> ky[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> r[i] >> cx[i] >> cy[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = dist(kx[i], ky[i], cx[j], cy[j]) < r[j] * r[j];
        }
    }

    for (int i = 0; i < k; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        cout << a[u].count() + a[v].count() - (a[u] & a[v]).count() * 2 << endl;
    }



        
    return 0;
}
