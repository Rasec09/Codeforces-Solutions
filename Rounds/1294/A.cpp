#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
  optimizar_io

  int t, a, b, c, n;

  cin >> t;
  while (t--) {
    cin >> a >> b >> c >> n;
    int maxN = max(a, max(b, c));
    int diff = (maxN - a) + (maxN - b) + (maxN - c);
    if (diff > n) {
      cout << "NO\n";
      continue;
    }
    diff -= n;
    cout << (diff % 3 ? "NO\n" : "YES\n");
  }
  return 0;
}
