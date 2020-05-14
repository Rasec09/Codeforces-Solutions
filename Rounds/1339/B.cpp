#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
  optimizar_io
  int tc, n, a[100010];
  vector<int> ans;

  cin >> tc;
  while (tc--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    int i = 0, j = n - 1;
    while (i < j) {
      ans.push_back(a[i]);
      ans.push_back(a[j]);
      i++; j--;
    }
    if (n & 1) 
      ans.push_back(a[i]);
    for (int i = n - 1; i >= 0; i--)
      cout << ans[i] << " ";
    cout << "\n";
    ans.clear();
  }
  return 0;
}
