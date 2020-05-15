#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
  optimizar_io
  int t, n, x, a[100010];

  cin >> t;
  while (t--) {
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    if (binary_search(a, a + n, x)) 
      cout << "1\n";
    else
      cout << max(2, (x + a[n - 1] - 1) / a[n - 1]) << "\n";
  }
  return 0;
}
