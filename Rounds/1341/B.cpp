#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int query(vector<int> &a, int l, int r) {
    return (l == 0 ? a[r] : a[r] - a[l - 1]); 
}

int main() {
    optimizar_io
    int tc, n, k, a[200010];
    vector<int> acum;
 
    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> a[i];
        acum.assign(n, 0);
        for (int i = 1; i < n - 1; i++) {
            if (a[i] > a[i - 1] and a[i] > a[i + 1])
                acum[i] = 1;
        }
        for (int i = 1; i < n; i++) 
            acum[i] += acum[i - 1];
        int ans = -1, idx;
        for (int i = 0; i + k <= n; i++) {
            int peaks = query(acum, i + 1, i + k - 2);
            if (peaks > ans) {
                ans = peaks;
                idx = i;
            }
        }
        cout << ans + 1 << " " << idx + 1 << "\n"; 
    }
    return 0;
}
