#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
    optimizar_io
  int tc, n;

  cin >> tc;
  while (tc--) {
    cin >> n;
    if (n % 4 != 0) {
      cout << "NO\n";
    }
    else {
      ll sumPar = 0;
      cout << "YES\n";
      for (int i = 0, x = 2; i < n / 2; i++, x += 2) {
        cout << x << " ";
        sumPar += x;
      }
      ll sumImpar = 0;
      for (int i = 0, x = 1; i < n / 2; i++, x += 2) {
        if (i + 1 == n / 2)
          cout << sumPar - sumImpar << "\n";
        else
          cout << x << " ";
        sumImpar += x;
      }
    }
  }
    return 0;
}
