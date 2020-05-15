#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {

  int n, a, b, k, h[200010];

  cin >> n >> a >> b >> k;
  for (int i = 0; i < n; i++) cin >> h[i];
  sort(h, h + n);
  int ans = 0, idx;
  for (idx = 0; idx < n; idx++) {
    if (h[idx] > a) {
      break;
    }
    else {
      ans++;
    }
  }
  vector<int> v;
  for (; idx < n; idx++) {
    int mod = h[idx] % (a + b);
    if (mod == 0) mod = a + b;
    if (mod <= a) {
      //cout << h[idx] << "\n";
      ans++;
    }
    else {
      int skipTurns = ((mod + a - 1) / a) - 1;
      if (k >= skipTurns) {
        v.push_back(skipTurns);
      }
    }
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    if (k >= v[i]) {
      k -= v[i];
      ans++;
    }
  }
  cout << ans << "\n";
  return 0;
}
