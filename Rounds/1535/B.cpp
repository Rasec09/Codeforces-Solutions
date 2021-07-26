#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

ll gcd(ll a, ll b) {
  return (b == 0 ? a : gcd(b, a % b));
}

int main() {
  optimizar_io
  int tc, n, a[2010];

  cin >> tc;
  while (tc--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> v(a, a + n);
    partition(v.begin(), v.end(), [](int i){return i % 2 == 0;});
    ll pairs = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (gcd(1LL * v[i], 2LL * v[j]) > 1)
          pairs++;
      }
    }
    cout << pairs << "\n";
  }
  return 0;
}

/* stuff you should look for:
  * int overflow, array bounds
  * special cases (n=1?), even odd
  * DON'T GET STUCK ON ONE APPROACH
*/
