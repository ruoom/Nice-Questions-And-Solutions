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

inline ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b != 0); } // divide a by b rounded up
inline ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b != 0); } // divide a by b rounded down
//template<class T> inline T qmul(T a, T b, T mod) { a %= mod; T res = 0; while (b != 0) { if (b & 1)res = (res + a) % mod; a = (a + a) % mod; b >>= 1; } return res; }
inline ll qmul(ll a, ll b, ll mod) { return (a * b - (ll)((long double)a / mod * b) * mod + mod) % mod; }
//template<class T> T qpow(T a, T b, T mod) { T res = 1; while (b != 0) { if (b & 1) res = qmul(res, a, mod); a = qmul(a, a, mod); b >>= 1; }return res; }
template<class T> inline T qpowqm(T a, T b, T mod) { T res = 1; a %= mod; while (b != 0) { if (b & 1) res = qmul(res, a, mod); a = qmul(a, a, mod); b >>= 1; }return res; }
template<class T> inline T qpow(T a, T b, T mod) { T res = 1; a %= mod; while (b != 0) { if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1; }return res; }
template<class T> inline T qpow(T a, T b) { T res = 1; while (b != 0) { if (b & 1) res = res * a; a = a * a; b >>= 1; }return res; }
template<class T> inline T gcd(T __m, T __n) { T __t; while (__n != 0) { __t = __m % __n; __m = __n; __n = __t; }return __m; }
template<class T> void Exgcd(T a, T b, T& x, T& y) { if (b == 0) x = 1, y = 0; else Exgcd(b, a % b, y, x), y -= a / b * x; }
const int dx[4]{ 1,0,-1,0 }, dy[4]{ 0,1,0,-1 }; // for every grid problem!!
//-------------------------------------------------------------------------------------


const int mod = 1e9 + 7;


signed main() {
    ____();


    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;

    vector<int> dpl(n), dpr(n), dp(n);

    stack<int> s;
    
    vector<int> firstSm(n, -1);

    for (int i = n-1; i >= 0; --i) {
        while (!s.empty() && a[s.top()] > a[i]) {
            firstSm[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    for (int i = 0; i < n; ++i) {
        dpl[i] = dpl[firstSm[i]] + (i - firstSm[i]) * a[i];
    }

    while (!s.empty()) { s.pop(); }
    
    fill(all(firstSm), n);
    for (int i = 0; i < n;++i) {
        while (!s.empty() && a[s.top()] > a[i]) {
            firstSm[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    
    for (int i = n - 1; i >= 0; --i) {
        dpr[i] = dpr[firstSm[i]] + (firstSm[i] - i) * a[i];
    }

    for (int i = 0; i < n;++i) {
        dp[i] = dpl[i] + dpr[i] - a[i];
    }
    int pos = max_element(all(dp)) - dp.begin();
    
    vector<int> ans(n);
    ans[pos] = a[pos];
    for (int i = pos - 1; i >= 0; --i) {
        ans[i] = min(ans[i + 1], a[i]);
    }
    for (int i = pos + 1; i < n; ++i) {
        ans[i] = min(ans[i - 1], a[i]);
    }
    cout << ans << endl;


    return 0;
} 
