#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

array<int,10000> a;
int n, lim, memo[10010][2010];

int dp(int idx, int last) {
	if (last < 0 or last >= lim) return 1e9;
	if (idx == n) return last;
	if (memo[idx][last] != -1) return memo[idx][last];
	return memo[idx][last] = min(max(last, dp(idx + 1, last - a[idx])), max(last, dp(idx + 1, last + a[idx])));
}

int main() {
	optimizar_io
	int tc;

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		int mx = *max_element(a.begin(), a.begin() + n);
		lim = 2 * mx + 1; 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < lim; j++)
				memo[i][j] = -1;
		}
		int ans = numeric_limits<int>::max();
		for (int start = 0; start < lim; start++) {
			ans = min(ans, dp(0, start));
		}
		cout << ans << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
