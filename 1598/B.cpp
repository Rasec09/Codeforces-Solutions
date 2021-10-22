#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int grid[1010][5];

bool solve(int n, int m) {
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			int cntA = 0, cntB = 0, both = 0;
			bool ok = true;
			for (int row = 0; row < n; row++) {
				if (grid[row][i] and !grid[row][j]) {
					cntA++;
				}
				else if (!grid[row][i] and grid[row][j]) {
					cntB++;
				}
				else if (grid[row][i] and grid[row][j]) {
					both++;
				}
				else {
					ok = false;
					break;
				}
			}
			if (ok and cntA <= n / 2 and cntB <= n / 2) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	optimizar_io
	int tc, n, m = 5;

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> grid[i][j];
			}
		}
		cout << (solve(n, m) ? "YES" : "NO") << "\n";
	}
	return 0;
}
/*
1
4
0 1 0 0 0
1 0 0 0 0
0 1 0 0 0
1 1 0 0 0
*/
