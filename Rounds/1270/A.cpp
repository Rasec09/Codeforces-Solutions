#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
  optimizar_io

  int t, n, k1, k2, a[110], b[110];

  cin >> t;
  while (t--) {
    cin >> n >> k1 >> k2;
    for (int i = 0; i < k1; i++) cin >> a[i];
    for (int i = 0; i < k2; i++) cin >> b[i];
    if (*max_element(a, a + k1) > *max_element(b, b + k2))
      cout << "YES\n";
    else
      cout << "NO\n"; 
  }
  return 0;
}
