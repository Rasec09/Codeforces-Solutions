#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int grid[3][100010];

int main() {
  optimizar_io

  int n, q, r, c;
  set<pair<int,int>> lava;

  cin >> n >> q;
  while (q--) {
    cin >> r >> c;
    if (grid[r][c]) {
      grid[r][c] = 0;
      if (r == 1) {
        for (int i = c - 1; i <= c + 1; i++)
          lava.erase(make_pair(c, i));
      }
      else {
        for (int i = c - 1; i <= c + 1; i++)
          lava.erase(make_pair(i, c));	
      }
    }
    else {
      grid[r][c] = 1;
      if (r == 1) {
        for (int i = c - 1; i <= c + 1; i++) {
          if (grid[2][i]) {
            lava.insert(make_pair(c, i));
          }
        }
      }
      else {
        for (int i = c - 1; i <= c + 1; i++) {
          if (grid[1][i]) {
            lava.insert(make_pair(i, c));
          }
        }
      }
    }
    cout << (lava.empty() ? "Yes\n" : "No\n");
  }
  return 0;
}
