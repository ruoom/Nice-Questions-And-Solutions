vector<int> w[1000001];
int cnt[1000001];
int ans[1000001];
bool p[1000001];
int maxx = 0;
int idd = 0;
 
int calc(int node, int pre) {
    int sum = 1;
    int id = 0;
    int mx = 0;
    for (auto& one : w[node]) {
        if (one == pre) {
            continue;
        }
        int a = calc(one, node);
        if (a > mx) {
            id = one;
            mx = a;
        }
        sum += a;
    }
    p[id] = 1;
    return sum;
}
 
void dfsdel(int node, int pre, int dep) {
    cnt[dep]--;
    for (auto& one : w[node]) {
        if (one == pre) {
            continue;
        }
        dfsdel(one, node, dep + 1);
    }
}
 
void ddfs(int node, int pre, int dep) {
    cnt[dep]++;
    if (cnt[dep] >= maxx) {
        if (cnt[dep] == maxx && idd > dep) {
            maxx = cnt[dep];
            idd = dep;
        }
        else if (cnt[dep] > maxx) {
            maxx = cnt[dep];
            idd = dep;
        }
    }
    for (auto& one : w[node]) {
        if (one == pre) {
            continue;
        }
        ddfs(one, node, dep + 1);
    }
}
 
void dfs(int node, int pre,int dep) {
    
    int id = 0;
    for (auto& one : w[node]) {
        if (one == pre) {
            continue;
        }
        if (p[one]) {
            id = one;
            continue;
        }
        dfs(one, node, dep + 1);
        dfsdel(one, node, dep + 1);
        idd = dep;
        maxx = cnt[idd];
    }
    if (id) {
        dfs(id, node, dep + 1);
    }
    
    cnt[dep]++;
    if (cnt[dep] >= maxx) {
        if (cnt[dep] == maxx && idd > dep) {
            maxx = cnt[dep];
            idd = dep;
        }
        else if (cnt[dep] > maxx) {
            maxx = cnt[dep];
            idd = dep;
        }
    }
 
    for (auto& one : w[node]) {
        if (one == pre || one == id) {
            continue;
        }
        ddfs(one, node, dep + 1);
    }
    ans[node] = idd - dep;
}
 
 
 
signed main() {
    __go();
 
    int n;
    cin >> n; 
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        w[u].push_back(v);
        w[v].push_back(u);
    }
 
    calc(1, 0);
    dfs(1, 0, 0);
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << endl;
    }
}
