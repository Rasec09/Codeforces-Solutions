#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;
int n, a[200010], memo[200010][2][3];

int dp(int idx, int turn, int k) {
	if (idx == n) return 0;
	//cout << idx << " " << turn << " " << k << "\n";
	if (memo[idx][turn][k] != -1) return memo[idx][turn][k];
	if (k == 2) {
		return memo[idx][turn][k] = dp(idx, 1 - turn, 0);
	}
	else if (k == 1) {
		if (turn)
			return memo[idx][turn][k] = min(dp(idx + 1, turn, k + 1), dp(idx + 1, 1 - turn, 0));
		else
			return memo[idx][turn][k] = min(dp(idx + 1, turn, k + 1), dp(idx + 1, 1 - turn, 0)) + a[idx];
	}
	else if (k == 0) {
		if (turn)
			return memo[idx][turn][k] = min(dp(idx + 1, 1 - turn, 0), dp(idx + 1, turn, 1));
		else
			return memo[idx][turn][k] = min(dp(idx + 1, 1 - turn, 0), dp(idx + 1, turn, 1)) + a[idx];
	}
}

int main() {
	optimizar_io
	int tc;

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2; j++)
				for (int k = 0; k < 3; k++)
					memo[i][j][k] = -1;
		}
		cout << dp(0, 0, 0) << "\n";
	}
	return 0;
}
