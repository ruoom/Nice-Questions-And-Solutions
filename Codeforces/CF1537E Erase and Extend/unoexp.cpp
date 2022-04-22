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

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string ss(1, s[0]);
    string ans;
    int c = 0;
    // 找最小的前缀(循环) dc(dcdcdc) > dcb(dcbdcb)
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[c]) {
            c++;
        } else if (s[i] < s[c]) {
            for (int j = i - c; j <= i; ++j) {
                ss.push_back(s[j]);
            }
            c = 0;
        } else {
            break;
        }
    }

    while (ans.size() < k) {
        ans.append(all(ss));
    }

    for (int i = 0; i < k; ++i) {
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
