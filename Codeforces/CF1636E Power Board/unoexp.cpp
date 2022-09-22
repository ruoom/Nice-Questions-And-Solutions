//#pragma GCC optimize(2)
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
template<class T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << " "; return os; }
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
template<class T> int Exgcd(T a, T b, T& x, T& y) { if (b == 0) { x = 1, y = 0; return a; } else { int d = Exgcd(b, a % b, y, x); y -= a / b * x; return d; } }
const int dx[4]{ 1,0,-1,0 }, dy[4]{ 0,1,0,-1 }; // for every grid problem!!
//-------------------------------------------------------------------------------------

std::array<int, 3> exgcd(int a, int b) {
    if (b == 0) {
        return {a, 1, 0};
    }
    auto [g, x, y] = exgcd(b, a % b);
    return {g, y, x - a / b * y};
}

const int N = 1003;
const int mod = 998244353;


signed main() {
    ____();

    int n, m;
    cin >> n >> m;
    int ans = 1;
    vector<bool> vis(n + 1);
    for (int i = 2; i <= n; ++i) {
        if (vis[i]) continue;
        //找到和i^j, j=1~m重复的
        //比如(i^2)^j, j=1~m/2
        int cnt = 0;
        //找i^2, i^3, i^4...的个数
        for (int j = i; j <= n; j *= i) {
            cnt++;
            vis[j] = 1;
        }
        //一共挑出来logn行
        //现在考虑怎么处理每行中重复的
        //枚举选择的某几行
        for (int i = 1; i < 1 << cnt; ++i) {
            //寻找第一行
            int first = 0;
            int cnt1 = 0;
            //找这些行中可以与第一行重复的元素个数
            //第一行: a^first^1 ~ a^first^m
            //后面全表示为a^x的形式
            int sum = 1;
            //(a^j)行
            for (int j = 1; j <= cnt; ++j) {
                if (i & 1 << (j - 1)) {
                    cnt1++;
                    if (!first) first = j;
                    //x行和y行中相同的元素 以a为底, 指数肯定是x和y的公倍数
                    //sum = min((cnt + 1) * m, lcm(sum, j));
                    sum = lcm(sum, j);
                }
            }
            //容斥
            //找和第一行相同的有多少个
            //m*first是第一行元素的最大的指数
            if (cnt1 & 1) {
                ans += m * first / sum;
            } else {
                ans -= m * first / sum;
            }
        }
    }
    cout << ans << endl;

    
    return 0;
}
