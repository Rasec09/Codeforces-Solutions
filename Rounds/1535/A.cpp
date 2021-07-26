#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
  optimizar_io
    int tc, a, b, c, d;

  cin >> tc;
  while (tc--) {
    cin >> a >> b >> c >> d;
    if (max(a, b) > min(c, d) and min(a, b) < max(c, d))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
