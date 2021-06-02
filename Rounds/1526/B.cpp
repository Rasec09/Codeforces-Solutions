#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
	
bitset<1210> dp[2];

int main() {
	optimizar_io
	int tc, n, amount = 1111;
	vector<int> coins;
	
	coins.push_back(11);
	coins.push_back(111);
	dp[0][0] = 1;
	for (int j = 1; j <= amount; j++) {
		if (j % coins[0] == 0)
			dp[0][j] = 1;
	}
	for (int i = 1; i < coins.size(); i++) {
		for (int j = 0; j <= amount; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - coins[i] >= 0)
				dp[i][j] = (dp[i][j] | dp[i][j - coins[i]]);
		}
	}
	cin >> tc;
	while (tc--) {
		cin >> n;
		if (n >= 1110)
			cout << "YES\n";
		else
			cout << (dp[int(coins.size()) - 1][n] ? "YES" : "NO") << "\n";
	}
	return 0;
}
