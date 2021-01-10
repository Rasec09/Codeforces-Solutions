#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
  optimizar_io
  int tc, x, a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  map<int,int> mp;

  for (int i = 0; i < (1 << 9); i++) {
    int sum = 0, num = 0;
    for (int j = 0; j < 9; j++) {
      if ((i & (1 << j))) {
        sum += a[j];
        num *= 10;
        num += a[j];
      }
    }
    mp[sum] = num;
  }
  cin >> tc;
  while (tc--) {
    cin >> x;
    if (mp.count(x)) {
      cout << mp[x] << "\n";
    }
    else {
      cout << "-1\n";
    }
  }
  return 0;
}
