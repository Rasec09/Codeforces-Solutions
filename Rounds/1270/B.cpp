#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
  optimizar_io

  int t, n, a[200010];

  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    bool flag = true;
    for (int i = 0; i + 1 < n; i++) {
      if (abs(a[i] - a[i + 1]) >= 2) {
        cout << "YES\n" << i + 1 << " " << i + 2 << "\n";
        flag = false;
        break;
      }
    }
    if (flag)
      cout << "NO\n";
  }
  return 0;
}
