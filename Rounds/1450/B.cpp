#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

ll Manhattan(ll x1, ll y1, ll x2, ll y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
  optimizar_io
  int tc, n, k, x[105], y[105];

  cin >> tc;
  while (tc--) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    bool possible = false;
    for (int i = 0; i < n; i++) {
      ll mx = -1;
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        ll dist = Manhattan(x[i], y[i], x[j], y[j]);
        mx = max(mx, dist);
      }
      if (mx <= k) {
        possible = true;
        break;
      }
    }
    cout << (possible ? "1\n" : "-1\n");
  }
  return 0;
}
