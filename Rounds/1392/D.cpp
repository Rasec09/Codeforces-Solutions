#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
#define L 0
#define R 1

int n, memo[200010][2][2][2][2];
string s;

int dp(int i, int prev1, int prev2, int first, int second) {
	if (i == n) { 
		if (prev2 == prev1 and prev2 == first) return 1e9;
		if (prev1 == first and prev1 == second) return 1e9;
		return 0;
	}
	if (memo[i][prev1][prev2][first][second] != -1) return memo[i][prev1][prev2][first][second]; 
	int curr = (s[i] == 'R' ? R : L), k = 0;
	if (curr == prev1) k++;
	if (curr == prev2) k++;
	if (k == 2) { //cambiar
		if (i == 2)
			return memo[i][prev1][prev2][first][second] = min({ dp(i + 1, 1 - curr, prev1, first, second),
															dp(i + 1, curr, 1 - prev1, first, 1 - second),
															dp(i + 1, curr, prev1, 1 - first, second)}) + 1;
		else
			return memo[i][prev1][prev2][first][second] = min({ dp(i + 1, 1 - curr, prev1, first, second),
															dp(i + 1, curr, 1 - prev1, first, second),
															dp(i + 1, curr, prev1, first, second)}) + 1;
	}
	else { // cambiar o no cambiar
		if (prev1 == prev2) { //RRL or LLR
			if (i == 2)
				return memo[i][prev1][prev2][first][second] = min({ dp(i + 1, curr, prev1, first, second),
																dp(i + 1, curr, 1 - prev1, first, 1 - second) + 1,
																dp(i + 1, curr, prev1, 1 - first, second) + 1});
			else
				return memo[i][prev1][prev2][first][second] = min({ dp(i + 1, curr, prev1, first, second),
																dp(i + 1, curr, 1 - prev1, first, second) + 1,
																dp(i + 1, curr, prev1, first, second) + 1});
		}
		else {
			if (prev2 == curr) { //No cambiar el de en medio e.g RLR
				if (i == 2)
					return memo[i][prev1][prev2][first][second] = min({ dp(i + 1, curr, prev1, first, second), 
																	dp(i + 1, 1 - curr, prev1, first, second) + 1,
																	dp(i + 1, curr, prev1, 1 - first, second) + 1});
				else
					return memo[i][prev1][prev2][first][second] = min({ dp(i + 1, curr, prev1, first, second), 
																	dp(i + 1, 1 - curr, prev1, first, second) + 1,
																	dp(i + 1, curr, prev1, first, second) + 1});
			}
			else if (prev1 == curr) { //No cambiar el de la izquierda eg. LRR
				if (i == 2)
					return memo[i][prev1][prev2][first][second] = min({ dp(i + 1, curr, prev1, first, second), 
																	dp(i + 1, 1 - curr, prev1, first, second) + 1,
																	dp(i + 1, curr, 1 - prev1, first, 1 - second) + 1});
				else
					return memo[i][prev1][prev2][first][second] = min({ dp(i + 1, curr, prev1, first, second),
																	dp(i + 1, 1 - curr, prev1, first, second) + 1,
																	dp(i + 1, curr, 1 - prev1, first, second) + 1});
			}
		}
	}
}

int main() {
	optimizar_io
	int tc;

	cin >> tc;
	while (tc--) {
		cin >> n >> s;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 2; j++) 
				for (int k = 0; k < 2; k++)
					for (int l = 0; l < 2; l++)
						for (int m = 0; m < 2; m++)
							memo[i][j][k][l][m] = -1;
		int first = s[0] == 'R' ? R : L;
		int second = s[1] == 'R' ? R : L;
		cout << dp(2, second, first, first, second) << "\n";
	}
	return 0;
}
