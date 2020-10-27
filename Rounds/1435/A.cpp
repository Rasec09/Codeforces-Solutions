#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
  optimizar_io
  int tc, n, a[105]; 

  cin >> tc;
  while (tc--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = n - 1; i >= 0; i--) {
      int x = a[i];
      if (i & 1)
        x *= -1;
      cout << x << " ";
    }
    cout << "\n";
  }
  return 0;
}
