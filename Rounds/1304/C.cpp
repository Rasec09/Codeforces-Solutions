#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

struct client {
  int time, low, hig;
};

int main() {
  optimizar_io

  int q, n, m, t, l, h;
  vector<client> c;

  cin >> q;
  while (q--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> t >> l >> h;
      c.push_back({t, l, h});
    }
    bool possible = true;
    int left = m, right = m, prev = 0;
    for (int i = 0; i < c.size(); i++) {
      left -= c[i].time - prev;
      right += c[i].time - prev;
      if (left <= c[i].hig and c[i].low <= right) {
        left = max(left, c[i].low);
        right = min(right, c[i].hig);
        prev = c[i].time;
      }
      else {
        possible = false;
        break;
      }
    }
    cout << (possible ? "YES\n" : "NO\n");
    c.clear();
  }
  return 0;
}
