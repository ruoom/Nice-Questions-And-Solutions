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
// #define int long long
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

int dp[1001][1001][2];
signed main() {
    ____();

    int n;
    cin >> n;
    //0 -> 2   1 -> 5 
    bool zero = 0;
    int pos;
    int x;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> x;
            if (x == 0) {
                pos = j;
                zero = 1;
            } 
            int y = x;
            while (y > 0 && y % 2 == 0) {
                dp[i][j][0]++;
                y /= 2;
            }
            y = x;
            while (y > 0 && y % 5 == 0) {
                dp[i][j][1]++;
                y /= 5;
            }
            if (i == j && i == 0)continue;
            if (i == 0) {
                dp[i][j][0] += dp[i][j - 1][0];
                dp[i][j][1] += dp[i][j - 1][1];
            } else if (j == 0) {
                dp[i][j][0] += dp[i - 1][j][0];
                dp[i][j][1] += dp[i - 1][j][1];
            } else {
                dp[i][j][0] += min(dp[i][j - 1][0], dp[i - 1][j][0]);
                dp[i][j][1] += min(dp[i][j - 1][1], dp[i - 1][j][1]);
            }
        }
    }
    int ans = min(dp[n - 1][n - 1][0], dp[n - 1][n - 1][1]);
    if (zero && ans > 1) {
        cout << 1 << endl;
        for (int i = 0; i < pos; ++i) {
            cout << "R";
        }
        for (int i = 0; i < n - 1;++i) {
            cout << "D";
        }
        for (int i = pos; i < n - 1; ++i) {
            cout << "R";
        }
        return 0;
    }
    
    bool k = dp[n - 1][n - 1][0] > dp[n - 1][n - 1][1];
    cout << ans << endl;
    int i = n - 1, j = n - 1;
    string res;
    while (i != 0 || j != 0) {
        if (i == 0) {
            j--;
            res.push_back('R');
        } else if (j == 0) {
            i--;
            res.push_back('D');
        } else {
            if (dp[i - 1][j][k] < dp[i][j - 1][k]) {
                i--;
                res.push_back('D');
            } else {
                j--;
                res.push_back('R');
            }
        }
    }
    for (int i = res.size() - 1; i >= 0; --i) {
        cout << res[i];
    }
    
    return 0;
}
