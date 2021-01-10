#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
  optimizar_io
  int tc, a, b, c;

  cin >> tc;
  while (tc--) {
    cin >> a >> b >> c;
    int k = a + b + c;
    if (k % 9 != 0) {
      cout << "NO\n";
    }
    else {
      k /= 9;
      if (a >= k and b >= k and c >= k)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
