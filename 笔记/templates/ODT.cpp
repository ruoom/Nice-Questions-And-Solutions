
class node {
public:
    int l, r;
    mutable int v;
    node(int l, int r, int v) : l(l), r(r), v(v) {};
    bool operator<(const node& o)const {
        return l < o.l;
    }
};
struct odt{
    set<node> t;
    auto split(int pos) {
        auto it = t.lower_bound(node(pos, 0, 0));
        if (it != t.end() && it->l == pos)return it;
        it--;
        int l = it->l, r = it->r, v = it->v;
        t.erase(it);
        t.insert(node(l, pos - 1, v));
        return t.insert(node(pos, r, v)).first;
    }
    void assign(int l, int r, int v) {
        auto end = split(r + 1);
        auto begin = split(l);
        t.erase(begin, end);
        t.insert(node(l, r, v));
    }
    void add(int l, int r, int v) {
        auto end = split(r + 1);
        for (auto it = split(l); it != end; ++it) {
            it->v += v;
        }
    }
    int find(int p){
        auto it = t.lower_bound(node(p,p,0));
        if(it != t.end() && it-> l == p) return it->v;
        return (--it)->v;
    }
    int kth(int l, int r, int k) {
        auto end = split(r + 1);
        vector<pii> v;
        for (auto it = split(l); it != end; ++it) {
            v.push_back(mkp(it->v, it->r - it->l + 1));
        }
        sort(all(v));
        for (int i = 0; i < v.size(); ++i) {
            k -= v[i].second;
            if (k <= 0)
                return v[i].first;
        }
    }
};
//-------------------------------------------------------------------------------------
