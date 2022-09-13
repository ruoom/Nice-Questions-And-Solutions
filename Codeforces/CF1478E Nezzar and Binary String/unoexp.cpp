#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define int long long
// #define ll long long
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
template<class T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << endl; return os; }
//-------------------------------------------------------------------------------------


class segtree {
public:
    struct node {
        int sum0, sum1;
        char val = 0;
        //初始值
        void apply(int l, int r, int v) {
            if (v == '0') sum0 = r - l + 1, sum1 = 0;
            else sum1 = r - l + 1, sum0 = 0;
            val = v;
        }
    };
    //pushup
    node unite(const node& a, const node& b) const {
        node res;
        res.sum0 = a.sum0 + b.sum0;
        res.sum1 = a.sum1 + b.sum1;
        res.val = 0;
        return res;
    }
    //laze tag
    inline void push(int u, int l, int r) {
        int mid = (l + r >> 1);
        int ls = u + 1, rs = u + ((mid - l + 1) << 1);
        if (tree[u].val == '0') {
            tree[ls].apply(l, mid, '0');
            tree[rs].apply(mid + 1, r, '0');
        } else if(tree[u].val == '1') {
            tree[ls].apply(l, mid, '1');
            tree[rs].apply(mid + 1, r, '1');
        }
        tree[u].val = 0;
    }

    inline void pull(int u, int ls, int rs) {
        tree[u] = unite(tree[ls], tree[rs]);
    }

    int n;
    vector<node> tree;

    void build(int u, int l, int r) {
        if (l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        int ls = u + 1, rs = u + ((mid - l + 1) << 1);
        build(ls, l, mid);
        build(rs, mid + 1, r);
        pull(u, ls, rs);
    }

    template <typename M>
    void build(int u, int l, int r, const vector<M>& v) {
        if (l == r) {
            tree[u].apply(l, r, v[l]);
            return;
        }
        int mid = (l + r) >> 1;
        int ls = u + 1, rs = u + ((mid - l + 1) << 1);
        build(ls, l, mid, v);
        build(rs, mid + 1, r, v);
        pull(u, ls, rs);
    }

    node get(int u, int l, int r, int ll, int rr) {
        if (ll <= l && r <= rr) {
            return tree[u];
        }
        int mid = (l + r) >> 1;
        int ls = u + 1, rs = u + ((mid - l + 1) << 1);
        push(u, l, r);
        node res{};
        if (rr <= mid) {
            res = get(ls, l, mid, ll, rr);
        } else if (ll > mid) {
            res = get(rs, mid + 1, r, ll, rr);
        } else {
            res = unite(get(ls, l, mid, ll, rr),
                get(rs, mid + 1, r, ll, rr));
        }
        pull(u, ls, rs);
        return res;
    }

    template <typename... M>
    void modify(int u, int l, int r, int ll, int rr, const M&... v) {
        if (ll <= l && r <= rr) {
            tree[u].apply(l, r, v...);
            return;
        }
        int mid = (l + r) >> 1;
        int ls = u + 1, rs = u + ((mid - l + 1) << 1);
        push(u, l, r);
        if (ll <= mid) {
            modify(ls, l, mid, ll, rr, v...);
        }
        if (rr > mid) {
            modify(rs, mid + 1, r, ll, rr, v...);
        }
        pull(u, ls, rs);
    }

    int find_first_knowingly(int u, int l, int r, const function<bool(const node&)>& f) {
        if (l == r) {
            return l;
        }
        push(u, l, r);
        int mid = (l + r) >> 1;
        int ls = u + 1, rs = u + ((mid - l + 1) << 1);
        int res;
        if (f(tree[ls])) {
            res = find_first_knowingly(ls, l, mid, f);
        } else {
            res = find_first_knowingly(rs, mid + 1, r, f);
        }
        pull(u, ls, rs);
        return res;
    }

    int find_first(int u, int l, int r, int ll, int rr, const function<bool(const node&)>& f) {
        if (ll <= l && r <= rr) {
            if (!f(tree[u])) {
                return -1;
            }
            return find_first_knowingly(u, l, r, f);
        }
        push(u, l, r);
        int mid = (l + r) >> 1;
        int ls = u + 1, rs = u + ((mid - l + 1) << 1);
        int res = -1;
        if (ll <= mid) {
            res = find_first(ls, l, mid, ll, rr, f);
        }
        if (rr > mid && res == -1) {
            res = find_first(rs, mid + 1, r, ll, rr, f);
        }
        pull(u, ls, rs);
        return res;
    }

    int find_last_knowingly(int u, int l, int r, const function<bool(const node&)>& f) {
        if (l == r) {
            return l;
        }
        push(u, l, r);
        int mid = (l + r) >> 1;
        int ls = u + 1, rs = u + ((mid - l + 1) << 1);
        int res;
        if (f(tree[rs])) {
            res = find_last_knowingly(rs, mid + 1, r, f);
        } else {
            res = find_last_knowingly(ls, l, mid, f);
        }
        pull(u, ls, rs);
        return res;
    }

    int find_last(int u, int l, int r, int ll, int rr, const function<bool(const node&)>& f) {
        if (ll <= l && r <= rr) {
            if (!f(tree[u])) {
                return -1;
            }
            return find_last_knowingly(u, l, r, f);
        }
        push(u, l, r);
        int mid = (l + r) >> 1;
        int ls = u + 1, rs = u + ((mid - l + 1) << 1);
        int res = -1;
        if (rr > mid) {
            res = find_last(rs, mid + 1, r, ll, rr, f);
        }
        if (ll <= mid && res == -1) {
            res = find_last(ls, l, mid, ll, rr, f);
        }
        pull(u, ls, rs);
        return res;
    }

    segtree(int _n) : n(_n) {
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1);
    }

    template <typename M>
    segtree(const vector<M>& v) {
        n = v.size();
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1, v);
    }

    node get(int ll, int rr) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return get(0, 0, n - 1, ll, rr);
    }

    char get(int p) {
        assert(0 <= p && p <= n - 1);
        return get(0, 0, n - 1, p, p).val;
    }

    template <typename... M>
    void modify(int ll, int rr, const M&... v) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        modify(0, 0, n - 1, ll, rr, v...);
    }

    // find_first and find_last call all FALSE elements
    // to the left (right) of the sought position exactly once

    int find_first(int ll, int rr, const function<bool(const node&)>& f) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return find_first(0, 0, n - 1, ll, rr, f);
    }

    int find_last(int ll, int rr, const function<bool(const node&)>& f) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return find_last(0, 0, n - 1, ll, rr, f);
    }
};




signed main() {
    ____();



    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string s, r;
        cin >> s >> r;
        vector<pii> d(q);
        cin >> d;
        
        vector<char> ss;
        for (char c : r)
            ss.push_back(c);
        segtree tr(ss);
        bool ans = 1;
        for (int i = q - 1; i >= 0;--i) {
            auto [l, r] = d[i];
            l--, r--;
            int len = r - l + 1;

            auto [cnt0, cnt1, v] = tr.get(l, r);
            if (2 * cnt0 == len) {
                ans = 0; break;
            }
            if (2 * cnt0 < len) {
                tr.modify(l, r, '1');
            } else {
                tr.modify(l, r, '0');
            }
        }
        for (int i = 0; i < n; ++i) {
            if (tr.get(i) != s[i]) {
                ans = 0; break;
            }
        }
        if (!ans) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    

    
    return 0;
}
