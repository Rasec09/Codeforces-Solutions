#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

ll gcd(ll a, ll b) {
  return (b == 0 ? a : gcd(b, a % b));
}

ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

int main() {
  optimizar_io
  int t;
  ll x;

  cin >> t;
  while (t--) {
    cin >> x;
    ll a, b;
    for (a = 1; ;a++) {
      b = x - a;
      if (gcd(a, b) + lcm(a, b) == x) {
        break;
      }
    }
    cout << a << " " << b << "\n";
  }
  return 0;
}
