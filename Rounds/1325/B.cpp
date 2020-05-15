#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
  optimizar_io
  int t, n, a[100010];
  set<int> diff;

  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      diff.insert(a[i]);
    }
    cout << diff.size() << "\n";
    diff.clear();
  }
  return 0;
}
