#pragma GCC optimize(2)
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
#define inf 2e18
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
void ____() {
    srand(time(0));
    cin.tie(0)->sync_with_stdio(0);  //cout.tie(0);
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

string s;
int p, n;

struct Node {
    int l, r;
    int val;
}tree[N << 2];


void build(int node, int l, int r) {
    if (l == r) {
        tree[node].val = 1;
        tree[node].l = l;
        tree[node].r = r;
        return;
    }
    int mid = l + r >> 1;
    int ls = node << 1;
    int rs = node << 1 | 1;
    build(rs, l, mid);
    build(ls, mid + 1, r);
    int d = s.size() - node;
    tree[node].l = l;
    tree[node].r = r;
    if (s[d] == '?') {
        tree[node].val = tree[ls].val + tree[rs].val;
    } else if(s[d] == '1'){
        tree[node].val = tree[ls].val;
    } else {
        tree[node].val = tree[rs].val;
    }
}

void md(int node) {
    int fa = node >> 1;
    int ls = node << 1;
    int rs = node << 1 | 1;
    if (s[n - node - 1] == '?') {
        tree[node].val = tree[ls].val + tree[rs].val;
    } else if (s[n - node - 1] == '1') {
        tree[node].val = tree[ls].val;
    } else {
        tree[node].val = tree[rs].val;
    }

    if (node == 1)return;
    md(fa);
}

signed main() {
    ____();

    int k;
    cin >> k;
    cin >> s;
    n = (1 << k);
    build(1, 1, n);
    int q;
    cin >> q;
    while (q--) {
        char c;
        cin >> p >> c;
        s[p - 1] = c;
        p = n - p;
        
        md(p);
        cout << tree[1].val << endl;
    }

    return 0;
}
