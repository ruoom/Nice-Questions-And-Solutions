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

const int mod = 998244353;
const int N = 5005;


vector<int> fac(N), inv(N);

void init(){
    fac[0] = inv[0] = 1;
    for(int i = 1; i < N; ++i){
        fac[i] = fac[i-1] * i % mod;
        inv[i] = qpow(fac[i], mod-2, mod);
    }
}
int C(int n, int m){
    return fac[n] * inv[m] % mod * inv[n-m] % mod;
}
int stling2(int n, int m){
    if(n < m) return 0;
    if(n >= 1 && m == 1)return 1;
    int res = 0;
    for(int k = 0, f = 1; k <= m; ++k, f = -f){
        res += f * C(m,k) * qpow(m-k,n,mod) % mod;
    }
    return res % mod;
}
//-------------------------------------------------------------------------------------

int C(int m, int n, int p)
{
    return m < n ? 0 : fac[m] * inv[n] % p * inv[m - n] % p;
}
int lucas(int m, int n, int p)
{
    return n == 0 ? 1 % p : lucas(m / p, n / p, p) * C(m % p, n % p, p) % p;
}

//-------------------------------------------------------------------------------------

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

signed main() {
    ____();

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k == 0 || count(all(s), '1') < k) {
        cout << 1 << endl;
        return 0;
    }
    init();
    vector<int> p;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            p.push_back(i);
        }
    }
    p.push_back(n);
    Z ans = 1;
    int m = p.size();
    int l = 0;
    for (int i = 0; i < m - k; i++) {
        int r = p[i + k] - 1;
        int len = r - l + 1;
        ans += C(len, k) - 1;
        l = p[i] + 1;
    }
    if(k!=1)
    for (int i = 0; i < m - k - 1; ++i) {
        int l = p[i] + 1;
        int r = p[i + k] - 1;
        debug(l, r);
        int len = r - l + 1;
        ans -= C(len, k - 1) - 1;
    }
    cout << ans.val() << endl;
    return 0;
}
