#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
  optimizar_io

  int t, n, a[200010];

  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < 2 * n; i++) cin >> a[i];
    sort(a, a + 2 * n);
    cout << abs(a[n] - a[n - 1]) << "\n";
  }
  return 0;
}
