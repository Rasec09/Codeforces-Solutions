#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
  optimizar_io

  int t, n;
  string s;

  cin >> t;
  while (t--) {
    cin >> n >> s;
    map<pair<int,int>,int> path;
    path[make_pair(0,0)] = 0;
    int x = 0, y = 0, dist = (1 << 30), l, r;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'D')
        y--;
      else if (s[i] == 'L')
        x--;
      else if (s[i] == 'R')
        x++;
      else if (s[i] == 'U')
        y++;

      pair<int,int> xy = make_pair(x,y);
      if (path.count(xy)) {
        int d = i - path[xy] + 1;
        if (d < dist) {
          dist = d;
          l = path[xy];
          r = i;
        }
      }
      path[xy] = i + 1;
    }
    if (dist == (1 << 30)) {
      cout << "-1\n";
    }
    else {
      cout << l + 1 << " " << r + 1 << "\n";
    }
  }
  return 0;
}
