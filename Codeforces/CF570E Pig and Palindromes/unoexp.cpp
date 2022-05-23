#pragma GCC optimize(2)
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
void ____() {
    srand(time(0));
    cin.tie(0)->sync_with_stdio(0);  //cout.tie(0);
#ifdef LOCAL
    bool uno = freopen("..\\in.txt", "r", stdin);
    bool exp = freopen("..\\out.txt", "w", stdout);
#endif
}
template<class T> istream& operator>>(istream& is, pair<T, T>& v) { is >> v.first >> v.second;       return is; }
template<class T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i;        return is; }
template<class T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << endl; return os; }
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
// 自动驱魔模板
int norm(int x) {
    if (x < 0) {
        x += mod;
    }
    if (x >= mod) {
        x -= mod;
    }
    return x;
}
template<class T>
T power(T a, int b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(mod - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, mod - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = int64_t(x) * rhs.x % mod;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
};
//-------------------------------------------------------------------------------------


const int N = 503;

char s[N][N];

//滚动数组优化第一维 now表示当前状态 pre表示前一状态
int f[2][N][N];
int now(int x) {
    return x & 1;
}
int pre(int x) {
    return x & 1 ^ 1;
}

signed main() {
    ____();

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> s[i][j];
        }
    }
    //首尾不同, 则不可能是回文 输出0
    if (s[1][1] != s[n][m]) {
        cout << 0 << endl;return 0;
    }
    //分别从头和尾走 x+y最多mx
    int mx = (n + m + 2) / 2;
    Z ans = 0;
    f[1][1][n] = 1;
    //枚举步数
    for (int i = 2; i <= mx; ++i) {
        //枚举两边的x
        for (int x1 = 1; x1 <= n; ++x1) {
            for (int x2 = 1; x2 <= n;++x2) {
                //计算出两边的y
                int y1 = i - x1, y2 = m + n + 2 - i - x2;
                //检查y是否合法
                if (y1 < 1 || y2 < 1 || y1 > m || y2 > m)continue;
                Z res = 0;
                f[now(i)][x1][x2] = 0;
                //不相等则无法回文, 跳过
                if (s[x1][y1] != s[x2][y2])continue;

                //前面四个状态 参考Acwing 275 传纸条
                res += f[pre(i)][x1][x2];
                res += f[pre(i)][x1][x2 + 1];
                res += f[pre(i)][x1 - 1][x2];
                res += f[pre(i)][x1 - 1][x2 + 1];
                
                f[now(i)][x1][x2] = res.val();
                //如果走完了 而且两点相差至少是1 就加上答案                
                if (i == mx && abs(x1 - x2) + abs(y1 - y2) <= 1) {
                    ans += res;
                }
            }
        }
    }

    cout << ans.val() << endl;

    
    return 0;
}
