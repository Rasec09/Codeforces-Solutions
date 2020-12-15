#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, n, m, dp[505][505];
	char grid[505][505];

	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> grid[i][j];
				dp[i][j] = (grid[i][j] == '*' ? 1 : 0);
			}
		}
		for (int i = n - 2; i >= 0; i--) {
			for (int j = 1; j + 1 < m; j++) {
				if (grid[i][j] == '*')
					dp[i][j] = min({dp[i + 1][j - 1], dp[i + 1][j], dp[i + 1][j + 1]}) + 1;
			}
		}
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				ans += dp[i][j];
		}
		cout << ans << "\n";
	}
	return 0;
}
