#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
  optimizar_io
  int t, n, d, a[110];

  cin >> t;
  while (t--) {
    cin >> n >> d;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
      while (a[i] and d - i >= 0) {
        d -= i;
        a[i]--;
        a[0]++;
      }
    }
    cout << a[0] << "\n";
  }
  return 0;
}
