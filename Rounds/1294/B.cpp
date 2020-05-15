#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
#define x first
#define y second

typedef pair<int,int> ii;

int main() {
  optimizar_io

  int t, n;

  cin >> t;
  while (t--) {
    cin >> n;
    vector<ii> puntos(n);
    for (int i = 0; i < n; i++) cin >> puntos[i].x >> puntos[i].y;
    sort(puntos.begin(), puntos.end());
    int _x = 0, _y = 0;
    string ans;
    bool possible = true;
    for (int i = 0; i < n; i++) {
      if (_x > puntos[i].x or _y > puntos[i].y) {
        possible = false;
        break;
      }
      for (int j = _x; j < puntos[i].x; j++) {
        ans.push_back('R');
        _x++;
      }
      for (int j = _y; j < puntos[i].y; j++) {
        ans.push_back('U');
        _y++;
      }
    }
    if (possible) {
      cout << "YES\n" << ans << "\n";
    }
    else {
      cout << "NO\n";
    }
  }
  return 0;
}
