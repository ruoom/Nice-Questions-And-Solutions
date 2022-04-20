int pre[5001];
int sz[5001];
signed main()
{
    __go();
    
    
    int t;
    cin >> t;
    sz[0] = 1;
    int sum = 0;
    int cnt = 0;
    int dep = 1;
    for (int i = 2; i < 5001; ++i) {
        if (cnt == 1 << dep) {
            dep++; cnt = 0;
        }
        sum += dep; cnt++;
        pre[i] = sum;
    }
    while (t--) {
        int n, d;
        cin >> n >> d;
        fill(sz + 1, sz + n + 2, 0);
        if (d<pre[n] || d>((n * (n - 1)) / 2)) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        int depnow = 0;
        int sumnow = 1;
        while (sumnow < n) {//sumnow nodes count
            depnow++;
            int nodes = 1 << depnow;
            if (sumnow + nodes > n) {
                sz[depnow] = n - sumnow;
            }
            else {
                sz[depnow] = nodes;
            }
            sumnow += sz[depnow];
        }
        sumnow = pre[n];//sumnow depth counts
        while (sumnow != d) {
            sumnow++;
            for (int i = depnow; i > 0; --i) {
                if (sz[i] > 1) {
                    sz[i]--;
                    sz[i + 1]++;
                    depnow = max(depnow, i + 1);
                    break;
                }
            }
        }
        int node = 2;
        int cnt = 0;
        queue<int> q;
        q.push(1ll);
        for (int i = 1; sz[i] != 0; ++i) {
            cnt = 0;
            int l = node;
            int last = q.front();
            q.pop();
            while (sz[i] > 0) {
                if (cnt == 2) {
                    cnt = 0;
                    last = q.front();
                    q.pop();
                }
                cout << last << " ";
                cnt++; node++;
                sz[i]--;
            }
            while (!q.empty()) {
                q.pop();
            }
            //debug(node);
            while (l < node) {
                q.push(l++);
            }
        }
        cout << endl;
    }
 
    return 0;
}
