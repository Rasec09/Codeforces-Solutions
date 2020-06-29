#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int n, a[200010];
ll dp[200010][3];

int main() {
	optimizar_io
	int tc;

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i <= n; i++) dp[i][0] = dp[i][1] = dp[i][2] = 0;
		for (int i = 0; i < n; i++) {
			if (i + 1 <= n) {
				dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + (i % 2 == 0 ? a[i] : 0));
				dp[i + 1][2] = max(dp[i + 1][2], max({dp[i][0], dp[i][1], dp[i][2]}) + (i % 2 == 0 ? a[i] : 0));
			}
			if (i + 2 <= n)
				dp[i + 2][1] = max(dp[i + 2][1], max(dp[i][0], dp[i][1]) + (i % 2 == 0 ? a[i + 1] : a[i]));
		}
		cout << max({dp[n][0], dp[n][1], dp[n][2]}) << "\n";
	}
	return 0;
}
