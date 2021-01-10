#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
  optimizar_io
  int tc, n;
  string r, b;

  cin >> tc;
  while (tc--) {
    cin >> n >> r >> b;
    int red = 0, blue = 0;
    for (int i = 0; i < n; i++) {
      if (r[i] > b[i])
        red++;
      else if (b[i] > r[i])
        blue++;
    }
    if (red > blue)
      cout << "RED\n";
    else if (blue > red)
      cout << "BLUE\n";
    else
      cout << "EQUAL\n";
  }
  return 0;
}
