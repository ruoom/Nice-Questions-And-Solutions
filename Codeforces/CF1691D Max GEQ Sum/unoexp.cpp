#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define LL
//#define ll long long
#define ull unsigned long long
#define endl '\n'
#define mkp(a,b) make_pair(a,b)
#define pii pair<int,int> 
#define umap unordered_map
#define all(x) x.begin(),x.end()
#define inf 2e18
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
#ifdef LL
#define int long long
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

const int N = 300005;
const int mod = 1e9 + 7;

int a[N];
int sum[N];
signed main() {
    ____();
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
    
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum[i] = a[i] + sum[i - 1];
        }
        stack<pii> s;
        bool ans = 1;
        
        for (int i = 1; i <= n; ++i) {
            while (!s.empty() && s.top().first <= a[i]) {
                if (sum[i] - sum[s.top().second - 1] > a[i]) {
                    ans = 0;
                }
                s.pop();
            }
            s.emplace(a[i], i);
        }
        s = stack<pii>();
        for (int i = n; i >= 1; --i) {
            while (!s.empty() && s.top().first <= a[i]) {
                if (sum[s.top().second] - sum[i - 1] > a[i]) {
                    ans = 0;
                }
                s.pop();
            }
            s.emplace(a[i], i);
        }
        cout << (ans ? "YES" : "NO") << endl;
    }

   


    
    return 0;
}
