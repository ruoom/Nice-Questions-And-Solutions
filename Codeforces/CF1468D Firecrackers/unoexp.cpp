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


signed main() {
    ____();


    int t;
    cin >> t;
    while (t--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        vector<int> s(m);
        cin >> s;
        sort(all(s));

        //最多能使用的时间
        int sum = abs(a - b) + (a < b ? a - 1 : n - a);
        //最多能放的炸弹数量
        int d = abs(a - b) - 1;
        d = min(d, m);

        int l = 0, r = d;
        while (l < r) {
            int x = (l + r + 1) / 2;
            int need = 0;
            for (int i = 1; i <= x; ++i) {
                need = max(need, s[x - i] + i);
            }
            debug(sum, need, x);
            if (need > sum) {
                r = x - 1;
            } else {
                l = x;
            }
        }
        cout << l << endl;

    }

    return 0;
}
