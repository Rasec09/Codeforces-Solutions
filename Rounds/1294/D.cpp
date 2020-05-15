#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
  optimizar_io

  int q, x, y, MEX = 0;

  cin >> q >> x;
  vector<int> cnt(x);
  while (q--) {
    cin >> y;
    cnt[y % x]++;
    while (cnt[MEX % x]) {
      cnt[MEX % x]--;
      MEX++;
    }
    cout << MEX << "\n";
  }
  return 0;
}
