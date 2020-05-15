#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
#define x first
#define y second

typedef pair<int,int> ii;

int main() {
  optimizar_io

  int t, n, a, b;

  cin >> t;
  while (t--) {
    cin >> n;
    a = -1;
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        a = i;
        n /= a;
        break;
      }
    }
    if (a == -1) {
      cout << "NO\n";
      continue;
    }
    b = -1;
    for (int i = a + 1; i * i <= n; i++) {
      if (n % i == 0) {
        b = i;
        n /= b;
        break;
      }
    }
    if (b == -1 or b == n) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n" << a << " " << b << " " << n << "\n";
  }
  return 0;
}
