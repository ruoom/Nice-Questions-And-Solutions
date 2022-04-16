
class dsu{
public:
    std::vector<int> rt, sz;
    dsu(int n) : rt(n+1), sz(n + 1, 1) {
         std::iota(rt.begin(), rt.end(), 0); 
    }
    int find(int x) {
        return rt[x] == x ? x : rt[x] = find(rt[x]);
    }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return 0;
        sz[x] += sz[y];
        rt[y] = x;
        return 1;
    }
    int size(int x) { return sz[find(x)]; }
};
//-------------------------------------------------------------------------------------
