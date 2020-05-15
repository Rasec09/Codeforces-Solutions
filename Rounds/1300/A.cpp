#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
  optimizar_io

  int t, n, a[110];

  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0, sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i];
      if (a[i] == 0)
        ans++;
    }
    if (sum + ans == 0)
      ans++;
    cout << ans << "\n";
  }
  return 0;
}
