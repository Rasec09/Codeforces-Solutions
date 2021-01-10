#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;
set<pair<int,int>> pos;

void dfs(int x, int y, int dir, int moves) {
  // cout << x << " " << y << " " << moves << "\n";
  if (moves == 0) {
    pos.insert(make_pair(x, y));
    return;
  }
  if (dir == 0) { // up
    dfs(x - 1, y, 2, moves - 1);
    dfs(x + 1, y, 3, moves - 1);
  }
  if (dir == 1) { // down
    dfs(x - 1, y, 2, moves - 1);
    dfs(x + 1, y, 3, moves - 1);
  }
  if (dir == 2) { // left
    dfs(x, y + 1, 0, moves - 1);
    dfs(x, y - 1, 1, moves - 1);
  }
  if (dir == 3) { // right
    dfs(x, y + 1, 0, moves - 1);
    dfs(x, y - 1, 1, moves - 1);
  }
  return;
}

int gauss(int x) {
  return (x * (x + 1)) / 2;
}

int main() {
  optimizar_io
  int n;
  /*
  cin >> n;
  for (int i = 0; i < 4; i++) {
    if (i == 0) {
      dfs(0, 1, i, n - 1);
    }
    if (i == 1) {
      dfs(0, -1, i, n - 1);
    }
    if (i == 2) {
      dfs(-1, 0, i, n - 1);
    }
    if (i == 3) {
      dfs(1, 0, i, n - 1);
    }
  }*/
  cin >> n;
  if (n & 1) {
    cout << 4 * gauss((n / 2) + 1) << "\n";
  }
  else {
    n /= 2;
    n++;
    cout << n * n << "\n";
  }
  return 0;
}
