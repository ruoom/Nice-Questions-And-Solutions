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


template <typename T>
struct Fenwick {
    const int n;
    std::vector<T> a;
    Fenwick(int n) : n(n), a(n) {}
    void add(int x, T v) {
        for (int i = x; i < n; i += i & -i) {
            a[i] += v;
        }
    }
    T sum(int x) {
        T ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i];
        }
        return ans;
    }
    T sum(int l, int r) {
        return sum(r) - sum(l);
    }
};
//-------------------------------------------------------------------------------------



signed main() {
    //____();

    int n, t;
    cin >> n >> t;
    Fenwick<int> f(n + 1);
    map<pii, int> qry;
    while (t--) {
        int k;
        cin >> k;
        int l = 1, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            int x;
            if (qry.count(mkp(1, mid))) {
                x = qry[mkp(1, mid)] + f.sum(mid);
            } else {
                cout << "? " << 1 << " " << mid << endl;
                cout.flush();
                cin >> x;
                qry[mkp(1, mid)] = x - f.sum(mid);
            }
            //1~mid中0的个数
            int cnt = mid - x;

            if (cnt < k) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        f.add(l, 1ll);
        cout << "! " << l << endl;
        cout.flush();
    }



    
    return 0;
}
