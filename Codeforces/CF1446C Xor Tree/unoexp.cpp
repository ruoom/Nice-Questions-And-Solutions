//#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define int long long
//#define ll long long
#define ull unsigned long long
#define endl '\n'
#define mkp(a,b) make_pair(a,b)
#define pii pair<int,int> 
#define all(x) x.begin(),x.end()
#define inf 2e18
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
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
template<class T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << " "; return os; }
//-------------------------------------------------------------------------------------

const int N = 100005;

int solve(const vector<int>& v, int p) {
    if (v.size() <= 1) return v.size();
    vector<int> l, r;
    for (auto& x : v) if (x & 1 << p) l.push_back(x);else r.push_back(x);
    if (l.empty()) return solve(r, p - 1);
    if (r.empty()) return solve(l, p - 1);
    return 1 + max(solve(l, p - 1), solve(r, p - 1));
}


signed main() {
    ____();

    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;

    cout << n - solve(a, 30) << endl;



    return 0;
}
