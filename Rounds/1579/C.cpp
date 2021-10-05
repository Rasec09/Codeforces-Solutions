#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

char grid[20][20];
bool mark[20][20];

int main() {
	optimizar_io
	int tc, n, m, k;

	cin >> tc;
	while (tc--) {
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		memset(mark, false, sizeof(mark));
		for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '*') {
                    int d = 0;
                    while (i - d - 1 >= 0 && j - d - 1 >= 0 && j + d + 1 < m) {
                        if (grid[i - d - 1][j - d - 1] == '.') {
                            break;
                        }
                        if (grid[i - d - 1][j + d + 1] == '.') {
                            break;
                        }
                        d += 1;
                    }
                    if (d >= k) {
                        for (int x = 0; x <= d; x++) {
                            mark[i - x][j - x] = true;
                            mark[i - x][j + x] = true;
                        }
                    }
                }
            }
        }
		bool res = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == '*' and !mark[i][j]) {
					res = false;
					break;
				}
			}
		}
		cout << (res ? "YES" : "NO") << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
