#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int n, h, l, r, a[2010], memo[2010][2010];

int dp(int i, int t) {
  if (i == n) return 0;
  if (memo[i][t] != -1) return memo[i][t];
  int tmp1 = (t + a[i]) % h, sum1 = 0; 
  if (tmp1 >= l and tmp1 <= r)
    sum1 = 1;
  int tmp2 = (t + (a[i] - 1)) % h, sum2 = 0; 
  if (tmp2 >= l and tmp2 <= r)
    sum2 = 1;
  return memo[i][t] = max(dp(i + 1, tmp1) + sum1, dp(i + 1, tmp2) + sum2);
}

int main() {
  optimizar_io

  cin >> n >> h >> l >> r;
  for (int i = 0; i < n; i++) cin >> a[i];
  memset(memo, -1, sizeof(memo));
  cout << dp(0, 0) << "\n";
  return 0;
}
