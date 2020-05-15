#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
  optimizar_io

  int t, n, a[2010];

  cin >> t;
  while (t--) {
    cin >> n;
    int impar = 0, par = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] & 1)
        impar++;
      else
        par++;
    }
    if (n & 1) {
      if (impar)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
    else {
      if (par and impar)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
