#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
  optimizar_io

  int n, a[100010];
  map<int,int> cnt;

  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 31; j++) {
      if (a[i] & (1 << j))
        cnt[j]++;
    }
  }
  int bit = -1;
  for (auto c : cnt) {
    if (c.second == 1)
      bit = c.first;
  }
  int idx = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] & (1 << bit)) {
      idx = i;
      break;
    }
  }
  cout << a[idx] << " ";
  for (int i = 0; i < n; i++) {
    if (i == idx) continue;
    cout << a[i] << " ";
  }
  cout << "\n";
  return 0;
}
