#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
  optimizar_io

  int t, s;

  cin >> t;
  while (t--) {
    cin >> s;
    int spend = 0;
    while (s >= 10) {
      int mod = s % 10;
      int q = s - mod;
      spend += q;
      s -= q;
      s += q / 10;
    }
    cout << spend + s << "\n";
  }
  return 0;
}
