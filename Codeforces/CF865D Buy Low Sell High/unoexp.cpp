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
//#define PI 3.141592653589793238462643383279
void __go() {
    srand(time(0));
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef LOCAL
    bool uno = freopen("..\\in.txt", "r", stdin);
    bool exp = freopen("..\\out.txt", "w", stdout);
#endif
}
template<class T> istream& operator>>(istream& is, pair<T, T>& v) { is >> v.first >> v.second;       return is; }
template<class T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i;        return is; }
template<class T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
//-------------------------------------------------------------------------------------



constexpr int mod = 1e9 + 7;

signed main(){
    __go();

    priority_queue<int,vector<int>,greater<int>> q;

    int n;
    cin >> n ;
    int ans = 0;
    for(int i = 0; i < n;++i){
        int a;
        cin >> a;
        if(!q.empty() && q.top() < a){
            ans += a - q.top();
            q.pop();
            q.push(a);
        }
        q.push(a);
    }
    cout << ans;
    return 0;
}

