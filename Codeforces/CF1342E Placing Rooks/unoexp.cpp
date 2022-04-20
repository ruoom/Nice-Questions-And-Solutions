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
#define MR Miller_Rabbin
#define PR Pollard_Rho
#define inf 2e18
//#define PI 3.141592653589793238462643383279
void __go() {
    srand(time(0));
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef LOCAL
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


constexpr int mod = 998244353;


const int N = 200005;
vector<int> fac(N), ifac(N);

void init(){
    fac[0] = ifac[0] = 1;
    for(int i = 1; i < N; ++i){
        fac[i] = fac[i-1] * i % mod;
        ifac[i] = qpow(fac[i], mod-2, mod);
    }
}
int C(int n, int m){
    return fac[n] * ifac[m] % mod * ifac[n-m] % mod;
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

#include<time.h>

signed main(){
    __go();

    init();

    int n,k;
    cin >> n >> k;
    int m = n - k;
    if(k >= n){
        cout << 0;
        return 0;
    }

    int ans = stling2(n,m) % mod;
    if(k!=0) ans = 2 * ans % mod;
    ans *= C(n,m);
    ans %= mod;
    while(ans < 0) ans += mod;
    cout << ans << endl;
    
    return 0;
}

