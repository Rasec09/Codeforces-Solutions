#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
  optimizar_io
  int tc, n, a[55];

  cin >> tc;
  while (tc--) {
    cin >> n;
    ll S = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      S += a[i];
    }
    ll b = 0;
    for (int i = 0; i < n; i++) {
      if (!(i & 1))
        b += abs(a[i] - 1);
    }
    if (2 * b <= S) {
      for (int i = 0; i < n; i++) {
        if (i & 1)
          cout << a[i] << " ";
        else
          cout << "1 ";
      }
      cout << "\n";
    }	
    else {
      for (int i = 0; i < n; i++) {
        if (i & 1)
          cout << "1 ";
        else
          cout << a[i] << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
