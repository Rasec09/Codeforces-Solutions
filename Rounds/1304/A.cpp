#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
  optimizar_io

  int t, x, y, a, b;

  cin >> t;
  while (t--) {
    cin >> x >> y >> a >> b;
    int d = y - x;
    if (d % (a + b) == 0)
      cout << d / (a + b) << "\n";
    else
      cout << "-1\n";
  }
  return 0;
}
