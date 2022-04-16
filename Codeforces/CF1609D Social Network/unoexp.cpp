/*
* どこへ行くかわからないけど、私はもう道にいる
            =@.
            @@@`
            .@@@@^                ..
            .@@@@@\]]`.      .]@@@@`
            @@@@@@@@@@@@@@@@@@@@@.
        ./@@@@@@@@@@@@@@@@@@@@/
        =@@@@@^,]\@@@@@@[@@@@@^
.]],[[@@@@@@@/O@@@@@\=@\@@@@@^
    .]/[..@@@@@@@@@@@@@@@@@@@@@@@.
        ,\@@@@@@@@@@@@@@@@@@/\.
            .[\@@@@@@@@@@@[..\` ..     .]].
                =@@@@@^        ,`     /.  .\
                =@@@@@@^             .@@`  =^
                =@@@@@@@^              .   =.
                \^=@@@@@@\                ,`
                =@@@@@@@@@@`             /.
                =@@@@@@@@@@@\          ]`
                =/@@@@@@@@@@@@\     ./.
                =\=@@@@@@@@@@@@@^ ,/
                =^.@@@@@@@@@@@@@@@`
                =^ @.\@@@@@@@@@@@@
                ,]@.`@^ .\@@@@@@@@@^
                ,[`[[[.,\@@@@@@@[[.
*/
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
void ____() {   //srand(time(0));
    ios::sync_with_stdio(0); cin.tie(0); //cout.tie(0);
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
        if (x == y) return false;
        sz[x] += sz[y];
        rt[y] = x;
        return true;
    }
    int size(int x) { return sz[find(x)]; }
};
//-------------------------------------------------------------------------------------


const int mod = 1e9 + 7;



signed main() {
    ____();

    int n, d;
    cin >> n >> d;
    dsu D(n + 1);
    int cur = 1;
    for (int i = 0; i < d; ++i) {
        int x, y;
        cin >> x >> y;
        if (!D.merge(x, y)) {
            cur++;
        }
        vector<int> a;
        for (int j = 1; j <= n; ++j) {
            if (D.find(j) == j) {
                a.push_back(D.size(j));
            }
        }
        sort(a.rbegin(), a.rend());
        cout << accumulate(a.begin(), a.begin() + cur, 0) - 1 << endl;
    }
    return 0;
} 
