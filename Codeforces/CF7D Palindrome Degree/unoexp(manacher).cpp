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

const int mod = 998244353;

vector<int> r;
void manacher(string& t) {
    string s;
    int n = t.size();
    s.push_back('$');
    for (int i = 0;i < n; ++i) {
        s.push_back(t[i]);
        s.push_back('$');
    }
    int mr = 0, mid = 0;
    n = s.size();
    r = vector<int>(n, 0);
    for (int i = 1;i < n;++i) {
        if (i < mr) {
            r[i] = min(r[2 * mid - i], mr - i);
        }
        while (
            i + r[i] + 1 < n && i - r[i] - 1 >= 0 &&
            s[i - r[i] - 1] == s[i + r[i] + 1])
            ++r[i];
        if (i + r[i] > mr) {
            mr = i + r[i];
            mid = i;
        }
    }
}


signed main() {
    ____();

    string s;
    cin >> s;

    manacher(s);
    vector<int> f(r.size(), 0);
    for (int i = 1; i < r.size(); ++i) {
        if (r[i] == i) {
            debug(s[i / 2]);
            f[i] = f[i / 2] + 1;
        }
    }

    int ans = Sum(f);
    cout << ans << endl;

    return 0;
}
