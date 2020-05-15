#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
  //optimizar_io

  int n;
  double ans = 0;

  scanf("%d", &n);
  for (int i = n; i > 0; i--) {
    ans += 1.0 / (double) i;
  }
  printf("%0.8lf\n", ans);
  return 0;
}
