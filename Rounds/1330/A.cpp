#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

bool check(int a[], int n, int x, int v) {
    int cnt = 0;
    for (int i = 1; i <= v; i++) {
        if (!binary_search(a, a + n, i))
            cnt++;
    }
    return cnt <= x;
}

int main() {
    optimizar_io
    int t, n, x, a[105];
    
    cin >> t;
    while (t--) {
        cin >> n >> x;
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        int ans = 1;
        for (int v = 1; v <= 201; v++) {
            if (check(a, n, x, v)) {
                ans = v;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
