#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
  optimizar_io

  int t;
  string a, b, c;

  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    bool ok = true;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] == b[i] and a[i] != c[i]) {
        ok = false;
        break;
      }
      ok = ok and (a[i] == c[i] or b[i] == c[i]);
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}
