constexpr int mod = 1e9 + 7;
 
 
signed main() {
    __go();
 
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<int> suff(n);
    map<int, int> cnt;
    for (auto& one : a) {
        cnt[one]++;
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        suff[i] = sum;  
    }
    long double ans = 0;
    for (int i = n - 1; i > 0; --i) {
        ans += i * a[i] - suff[i - 1];
        ans += cnt[a[i] + 1];
        ans -= cnt[a[i] - 1];
        cnt[a[i]]--;
    }
    cout << fixed << setprecision(0) << ans;
}
