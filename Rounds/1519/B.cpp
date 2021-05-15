#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

bool dp[105][105][10010];

int main() {
	optimizar_io
	int tc, n, m, k;	

	dp[0][0][0] = true;
	for (int x = 0; x <= 100; x++) {
		for (int y = 0; y <= 100; y++) {
			if (x == 0 and y == 0) continue;
			for (int cost = 0; cost <= 10000; cost++) {
				if (x)
					dp[x][y][cost] |= dp[x - 1][y][cost - y - 1];
				if (y)
					dp[x][y][cost] |= dp[x][y - 1][cost - x - 1];
			}
		}
	}
	cin >> tc;
	while (tc--) {
		cin >> n >> m >> k;
		n--; m--;
		cout << (dp[n][m][k] ? "YES\n" : "NO\n");
	}
	return 0;
}
