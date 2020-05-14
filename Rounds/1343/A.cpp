#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

vector<int> div(int n) {
  vector<int> d;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      d.push_back(i);
      d.push_back(n / i);
    }
  }
  return d;
}

int main() {
    optimizar_io
  int tc, n;
  vector<int> pow2;

  int x = 1;
  while (x <= 1e9) {
    pow2.push_back(x - 1);
    x <<= 1;
  }
  cin >> tc;
  while (tc--) {
    cin >> n;
    if (binary_search(pow2.begin(), pow2.end(), n))
      cout << "1\n";
    else {
      vector<int> d = div(n);
      for (int i = 0; i < d.size(); i++) {
        if (binary_search(pow2.begin(), pow2.end(), d[i])) {
          cout << n / d[i] << "\n";
          break;
        }
      }
    }
  }
    return 0;
}
