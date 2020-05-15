#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
  optimizar_io
  int t, n, a[105];

  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int minVal = *min_element(a, a + n);
    bool possible = true;
    for (int i = 0; i < n; i++) {
      a[i] -= minVal;
      a[i] %= 2;
      if (a[i]) {
        possible = false;
        break;
      }
    }
    cout << (possible ? "YES\n" : "NO\n");
  }
  return 0;
}
