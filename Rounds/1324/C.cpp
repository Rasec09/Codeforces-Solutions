#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
  optimizar_io
  int t, n;
  string s;

  cin >> t;
  while (t--) {
    cin >> s;
    s.insert(0, "R");
    n = s.size();
    int l = 0, r = 0, ans = -1;
    while (l < n and r < n) {
      if (s[l] == 'R') {
        r = l + 1;
        while (s[r] != 'R' and r < n) r++;
        //cout << l << " " << r << "\n";
        ans = max(ans, r - l);
        l = r;
      }
      else {
        l++;
      }
    }
    if (ans == -1)
      cout << n + 1 << "\n";
    else
      cout << ans << "\n";
  }
  return 0;
}
