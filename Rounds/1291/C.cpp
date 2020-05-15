#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {

  int t, n, m, k, a[3510];

  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    k = min(k, m - 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for (int x = 0; x <= k; x++) {
      int best = 1e9;
      for (int y = 0; y <= m - 1 - k; y++)
        best = min(best, max(a[x + y], a[x + y + (n - m)]));
      ans = max(ans, best);
    }
    cout << ans << "\n";
  }
  return 0;
}
