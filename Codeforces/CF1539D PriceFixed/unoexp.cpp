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


    int n;
    cin >> n;
    vector<array<int, 2> > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1];
    }
    sort(all(a), [](array<int, 2>& a, array<int, 2>& b) {
        return a[1] > b[1];});
    int l = 0, r = n - 1;
    int ans = 0;
    int sum = 0;
    while (l <= r) {
        if (sum >= a[r][1]) {
            ans += a[r][0];
            sum += a[r][0];
            r--;
        } else {
            int nd = a[r][1] - sum;
            if (a[l][0] >= nd) {
                a[l][0] -= nd;
                ans += 2 * nd;
                sum += nd;
            } else {
                ans += 2 * a[l][0];
                sum += a[l][0];
                l++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
