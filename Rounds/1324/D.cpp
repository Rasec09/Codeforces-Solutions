#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
  optimizar_io
  int n, a[200010], b[200010], c[200010];

  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) {
    c[i] = a[i] - b[i];
  }
  sort(c, c + n);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (c[i] <= 0) {
      int target = 1 - c[i];
      int pos = lower_bound(c, c + n, target) - c;
      ans += n - pos;
    }
    else {
      ans += n - i - 1;
    }
  }
  cout << ans << "\n";
  return 0;
}
