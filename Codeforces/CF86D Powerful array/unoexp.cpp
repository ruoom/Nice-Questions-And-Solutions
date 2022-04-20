int ans[200005];
int c[1000005];
signed main()
{
    __go();
    
    
 
    int n, t;
    cin >> n >> t;
    
    int cnt = sqrt(n) + 1;
    vector<int> sq(cnt + 5);
 
    int cc = -cnt;
    int i = 0;
    while (cc < n) {
        cc += cnt;
        sq[i++] = cc;
    }
    debug(i, sq.size());
 
    vector<int32_t> a(n);
    cin >> a;
    vector<pair<pii, int> >s(t);
    for (int i = 0; i < t;++i) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        s[i] = mkp(mkp(l, r), i);;
    }
 
    auto cmp = [=](pair<pii, int> a, pair<pii, int> b)->bool{
        int al = a.first.first, ar = a.first.second;
        int bl = b.first.first, br = b.first.second;
        if (lower_bound(all(sq), al) == lower_bound(all(sq), bl)) {
            return ar > br;
        }
        else {
            return al <= bl;
        }
    };
 
    sort(all(s), cmp);
    int cur = a[0];
    c[cur] = 1;
    int l = 0, r = 0;
    for (int i = 0; i < t; ++i) {
        int id = s[i].second;
        
        int al = s[i].first.first;
        int ar = s[i].first.second;
 
        while (r < ar) {
            int nxt = a[++r];
            cur -= nxt * c[nxt] * c[nxt];
            c[nxt]++;
            cur += nxt * c[nxt] * c[nxt];
        }
 
        while (l > al) {
            int nxt = a[--l];
            cur -= nxt * c[nxt] * c[nxt];
            c[nxt]++;
            cur += nxt * c[nxt] * c[nxt];
        }
 
        while (l < al) {
            int pre = a[l++];
            cur -= pre * c[pre] * c[pre];
            c[pre]--;
            cur += pre * c[pre] * c[pre];
        }
 
        while (r > ar) {
            int pre = a[r--];
            cur -= pre * c[pre] * c[pre];
            c[pre]--;
            cur += pre * c[pre] * c[pre];
        }
 
        ans[id] = cur;
    }
 
    for (int i = 0; i < t; ++i) {
        cout << ans[i] << endl;
    }
 
    return 0;
}
