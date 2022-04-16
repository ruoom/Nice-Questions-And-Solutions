
template<class T>
bool gs(vector<vector<T>>& a, int n, int m) {
    int curi = 0;
    for (int j = 0; j < m; ++j) {
        int i;
        for (i = curi; i < n;++i) {
            if (a[i][j])
                break;
        }
        if (i >= n)break;
        if (a[i][j] == 0)
            continue;
        for (int k = 0; k < m; ++k) {
            swap(a[i][k], a[curi][k]);
        }
        for (int k = m - 1; k >= j; --k) {
            a[curi][k] /= a[curi][j];
        }
        for (int k = 0; k < n; ++k) {
            if (k != curi) {
                for (int h = m - 1; h >= j; --h) {
                    a[k][h] -= a[curi][h] * a[k][j];
                }
            }
        }
        curi++;
    }
    return curi == n;
}
//-------------------------------------------------------------------------------------
