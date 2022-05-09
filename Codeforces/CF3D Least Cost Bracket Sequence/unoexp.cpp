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
template<class T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
//-------------------------------------------------------------------------------------

const int mod = 998'244'353;



signed main() {
    ____();

    string s;
    cin >> s;
    int n = s.size();
    int m = 0;
    priority_queue<pii> q;
    int cur = 0;
    int ans = 0;
    bool ok = 1;
    for(int i = 0; i < n ; ++i){
        if(s[i] == '('){
            cur++;
        }else if(s[i] ==')'){
            cur--;
        }else{
            int u,v;
            cin >> u >> v;
            cur--;
            s[i] = ')';
            q.emplace(v-u, i);
            ans += v;
        }
        if(cur < 0){
            if(q.empty()){
                cout << -1 << endl;
                return 0;
            }
            pii d = q.top();
            cur += 2;
            q.pop();
            ans -= d.first;
            s[d.second] = '(';
        }
    }
    if(cur != 0)
        cout << -1<< endl;
    else
        cout << ans << endl << s << endl;

    
    return 0;
}
