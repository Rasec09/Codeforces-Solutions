#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
  optimizar_io

  int t, n, a[100010];

  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    ll sum = a[0], _xor = a[0];
    for (int i = 1; i < n; i++) {
      sum += a[i];
      _xor ^= a[i];
    }
    if (sum == 2 * _xor) {
      cout << "0\n\n";
      continue;
    }
    cout << "2\n" << _xor << " " << sum + _xor << "\n";
  }
  return 0;
}
