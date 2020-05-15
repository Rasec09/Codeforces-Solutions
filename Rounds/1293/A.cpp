#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
  optimizar_io

  int t, n, s, k, closed[1010];

  cin >> t;
  while (t--) {
    cin >> n >> s >> k;
    for (int i = 0; i < k; i++) cin >> closed[i];
    sort(closed, closed + k);
    if (!binary_search(closed, closed + k, s)) {
      cout << "0\n";
      continue;
    }
    else {
      int up = s + 1;
      while (up <= n and binary_search(closed, closed + k, up)) {
        up++;
      }
      int down = s - 1;
      while (down > 0 and binary_search(closed, closed + k, down)) {
        down--;
      }
      if (down == 0) {
        cout << up - s << "\n";
      }
      else if (up == n + 1) {
        cout << s - down << "\n";
      }
      else {
        cout << min(up - s, s - down) << "\n";
      }
    }
  }
  return 0;
}
