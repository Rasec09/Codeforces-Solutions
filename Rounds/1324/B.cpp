#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

bool palindromo(int a[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j > i; j--) {
      if (a[i] == a[j] and i + 1 < j)
        return true;
    }
  }
  return false;
}

int main() {
  optimizar_io
  int t, n, a[5010];

  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << (palindromo(a, n) ? "YES\n" : "NO\n");
  }
  return 0;
}
