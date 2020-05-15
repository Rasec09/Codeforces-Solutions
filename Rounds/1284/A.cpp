#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
  optimizar_io

  int n, m, q, y;
  string s[25], t[25];

  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> s[i];
  for (int i = 1; i <= m; i++) cin >> t[i];
  cin >> q;
  while (q--) {
    cin >> y;
    //cout << y % n << " " << y % m << "\n";
    int i = y % n, j = y % m;
    if (i == 0) i = n;
    if (j == 0) j = m;
    cout << s[i] << t[j] << "\n";
  }
  return 0;
}
