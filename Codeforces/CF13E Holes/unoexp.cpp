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
#define PI 3.1415926535898
void __go() {
    srand(time(0));
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef LOCAL
    bool uno = freopen("../in.txt", "r", stdin);
    bool exp = freopen("../out.txt", "w", stdout);
#endif
}
template<class T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i;        return is; }
template<class T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<class T> istream& operator>>(istream& is, pair<T, T>& v) { is >> v.first >> v.second;       return is; }
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
string to_string(const string& s) {
    return '"' + s + '"';
}
string to_string(const char* s) {
    return to_string((string)s);
}
string to_string(bool b) {
    return (b ? "true" : "false");
}
string to_string(vector<bool> v) {
    bool first = true; string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) res += ", "; first = false; res += to_string(v[i]);
    }res += "}"; return res;
}
template <size_t N>
string to_string(bitset<N> v) {
    string res = ""; for (size_t i = 0; i < N; i++) { res += static_cast<char>('0' + v[i]); }
    return res;
}
template <typename A>
string to_string(A v) {
    bool first = true; string res = "{"; for (const auto& x : v)
    {
        if (!first) res += ", "; first = false; res += to_string(x);
    }res += "}"; return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cout << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cout << " " << to_string(H); debug_out(T...);
}
#ifdef LOCAL
#define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
//-------------------------------------------------------------------------------------
//#define ls(x) tree[x].ls
//#define rs(x) tree[x].rs
////#define lc(x) x << 1
////#define rc(x) x << 1 | 1
//#define val(x) tree[x].val
//#define mark(x) tree[x].mark

//-------------------------------------------------------------------------------------
//bool space;
inline int read() {
    //space = 0;
    int w = 0, f = 1;
    char c = getchar();
    while (!isdigit(c))if (c == '-')f = -1, c = getchar();
    while (isdigit(c))w = (w << 1) + (w << 3) + (c ^ 48), c = getchar();
    //if (c == ' ')space = 1;
    return w * f;
}
//-------------------------------------------------------------------------------------

constexpr int mod = 1e9 + 7;

int32_t d[100001];
int32_t cnt[100001];
int32_t last[100001];
int32_t bl[100001];
signed main(){
    __go();

    int n,m;
    cin >> n >> m;
    int sq = sqrt(n);
    for(int i = 1; i <= n; ++i){
        cin >> d[i];
    }
    for(int i = 1; i <= n; ++i){
        bl[i] = fdiv(i-1,sq);  
    }

    for(int i = n; i >= 1; --i ){
        if( bl[i + d[i]] != bl[i] || i + d[i] > n){
            cnt[i] = 1;
            last[i] = i;
        }else{
            cnt[i] = cnt[i+d[i]] + 1;
            last[i] = last[i+d[i]];
        }
    }

    for(int i = 0; i < m; ++i){
        int o;
        cin >> o;
        if(o){
            int a;
            cin >> a;
            int c = 0;
            while(1){
                c += cnt[a];
                a = last[a];
                if( a + d[a] > n){
                   break;
                }
                a += d[a];
            }
            cout << a << ' ' << c << endl;
        }
        else{
            int a ,b;
            cin >> a >> b;
            d[a] = b;
            int nowst = lower_bound(bl+1,bl+n+1,bl[a]) - bl;
            
            for(int i = a; i >= nowst ; --i){
                cnt[i] = 0;  
                if( bl[i + d[i]] != bl[i] || i + d[i] > n){
                    last[i] = i;
                    cnt[i] = 1;
                }else{
                    cnt[i] = cnt[i+d[i]] + 1;
                    last[i] = last[i+d[i]];
                }
            }
            
        }
    }
    return 0;
}

