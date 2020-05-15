#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
  optimizar_io

  int t, a, b, x, y;

  cin >> t;
  while (t--) {
    cin >> a >> b >> x >> y;
    cout << max((x * b), max((a - x - 1) * b, max(a * y, a * (b - y - 1)))) << "\n";
  }
  return 0;
}
