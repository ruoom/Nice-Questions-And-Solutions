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
#include<numeric>
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
template<class T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' ';return os; }
//-------------------------------------------------------------------------------------

class dsu{
public:
    std::vector<int> rt, sz;
    dsu(int n) : rt(n+1), sz(n + 1, 1) {
         std::iota(rt.begin(), rt.end(), 0); 
    }
    int find(int x) {
        return rt[x] == x ? x : rt[x] = find(rt[x]);
    }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return 0;
        sz[x] += sz[y];
        rt[y] = x;
        return 1;
    }
    int size(int x) { return sz[find(x)]; }
};
//-------------------------------------------------------------------------------------

set<int> w[100005];

signed main() {
    ____();

    int n, m;
    cin >> n >> m;
    dsu d(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        w[u].emplace(v);
        w[v].emplace(u);
    }
    
    set<int> s;
    for (int i = 1; i <= n;++i) {
        map<int, int> cnt;
        for (auto& c : w[i]) {
            cnt[d.find(c)]++;
        }
        for (auto& c : s) {
            int sz = d.size(c);
            if (cnt[d.find(c)] < sz) {
                d.merge(c, i);
            }
        }
        s.emplace(d.find(i));
    }
    set<int>k;
    for (auto& c : s) {
        k.emplace(d.find(c));
    }
    cout << k.size() - 1 << endl;

    return 0;
}
