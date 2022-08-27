#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 2e18
const int N = 200005;

int a[N];
int f[N];
bool ans[N];
signed main() {

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    int s1 = -inf, s2 = inf;
    for (int i = 1; i <= n; ++i) {
        if (a[i] <= s1 && a[i] >= s2) {
            cout << "NO" << endl;
            return 0;
        }

        if (a[i] <= s1) {
            s2 = a[i];
            ans[i] = 1;
        } else if (a[i] >= s2) {
            s1 = a[i];
        } else {
            if (a[i + 1] > a[i]) {
                s1 = a[i];
            } else {
                s2 = a[i];
                ans[i] = 1;
            }
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i) {
        cout << (ans[i] ? 1 : 0) << " ";
    }


    return 0;
}
