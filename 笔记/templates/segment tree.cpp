// https://zhuanlan.zhihu.com/p/115011925?from_voters_page=true
class segtree {
public:
    struct node {
        int val = -1;
        int mn = -1;
        int mx = -1;
        //初始值
        void apply(int l, int r, int v) {
            val = mn = mx = v;
        }
    };
    //pushup
    node unite(const node& a, const node& b) const {
        node res;
        res.mn = min(a.mn, b.mn);
        res.mx = max(a.mx, b.mx);
        return res;
    }
    //laze tag
    inline void push(int u, int l, int r) {
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

    node get(int p) {
        assert(0 <= p && p <= n - 1);
        return get(0, 0, n - 1, p, p);
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
