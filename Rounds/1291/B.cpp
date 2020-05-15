#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
  optimizar_io

  int t, n, a[300010];

  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int i = 0, j = n - 1;
    for (i = 0; i < n; i++) {
      if (a[i] < i)
        break;
    }
    i--;
    for (j = n - 1; j >= 0; j--) {
      if (a[j] < n - j - 1)
        break;
    }
    j++;
    cout << (i < j ? "No\n" : "Yes\n");
  }
  return 0;
}
