#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long int ll;

int n, a[2010];
ll dp[2010][2010];

int main() {
	optimizar_io
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= i; k++) {
			if (dp[i - 1][k - 1] != -1 and dp[i - 1][k - 1] + a[i] >= 0)
				dp[i][k] = max(dp[i - 1][k], dp[i - 1][k - 1] + a[i]);
			else
				dp[i][k] = dp[i - 1][k];
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		for (int k = 0; k <= n; k++) {
			if (dp[i][k] >= 0)
				ans = max(ans, k);
		}
	}
	cout << ans << "\n";
	return 0;
}
