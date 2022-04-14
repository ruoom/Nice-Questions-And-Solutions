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
    vector<int> a(n);
    cin >> a;

    int sum = Sum(a);
    if (sum & 1) {
        cout << 0 << endl;
        return 0;
    }
    sum /= 2;

    //前i个数里是否能取到sum = j
    vector<bool> f(200005, false);
    f[0] = 1;
    for (int i = 0; i < n; ++i) {
        //这里要反着来
        for (int j = 200005; j >= a[i]; --j) {
            if (f[j - a[i]]) f[j] = 1;
        }
    }
    if (f[sum] == 0) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    sum *= 2;
    for (int i = 0; i < n; ++i) {
        if ((sum - a[i]) & 1 || f[(sum - a[i]) / 2] == 0) {
            ans = i + 1;break;
        }
    }
    cout << 1 << endl << ans << endl;

    return 0;
}
