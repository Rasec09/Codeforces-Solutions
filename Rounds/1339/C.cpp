#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
    optimizar_io
    int tc, n, a[100010];

    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        int ans = -1;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] > a[i]) {
                int diff = a[i - 1] - a[i];
                int steps = log2(diff);
                ans = max(ans, steps);
                a[i] = a[i - 1];
            }
        }
        cout << ans + 1 << "\n";
    }
    return 0;
}
