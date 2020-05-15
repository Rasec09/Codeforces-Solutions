#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
  optimizar_io

  int t, a[10];

  cin >> t;
  while (t--) {
    for (int i = 0; i < 3; i++) cin >> a[i];
    sort(a, a + 3, greater<int>()); 
    int ans = 0;
    if (a[0] > 0) {
      ans++;
      a[0]--;
    }
    if (a[1] > 0) {
      ans++;
      a[1]--;
    }
    if (a[2] > 0) {
      ans++;
      a[2]--;
    }
    if (a[0] > 0 and a[1] > 0) {
      ans++;
      a[0]--;
      a[1]--;
    }
    if (a[0] > 0 and a[2] > 0) {
      ans++;
      a[0]--;
      a[2]--;
    }
    if (a[1] > 0 and a[2] > 0) {
      ans++;
      a[1]--;
      a[2]--;
    }
    if (a[0] > 0 and a[1] > 0 and a[2] > 0) {
      ans++;
      a[0]--;
      a[1]--;
      a[2]--;
    }
    cout << ans << "\n";
  }
  return 0;
}
