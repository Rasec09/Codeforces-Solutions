#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
 
int main() {
	optimizar_io
	int tc, n;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> n >> s;
		n = s.size();
		vector<vector<char>> grid(n, vector<char>(n, '.'));
		for (int i = 0; i < n; i++) grid[i][i] = 'X';
		// fill draws
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				for (int j = 0; j < n; j++) {
					if (i == j) continue;
					grid[i][j] = grid[j][i] = '=';
				}
			}
		}
		// fill wins
		bool possible = true;
		for (int i = 0; i < n; i++) {
			if (s[i] == '2') {
				bool ok = false;
				for (int j = 0; j < n; j++) {
					if (i == j) continue;
					if (grid[i][j] == '.' and grid[j][i] == '.') {
						grid[i][j] = '+';
						grid[j][i] = '-';
						ok = true;
						break;
					}
				}
				if (!ok) {
					possible = false;
					break;
				}
			}
		}
		if (!possible) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == '.') {
					grid[i][j] = grid[j][i] = '=';
				}
				cout << grid[i][j];
			}
			cout << "\n";
		}
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
