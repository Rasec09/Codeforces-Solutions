#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

array<int,8> dx = {1, -1, 0, 0, 1, -1,- 1, 1};
array<int,8> dy = {0,  0, 1,-1, 1, 1, -1, -1};

int main() {
	optimizar_io
	int tc, r, c;

	cin >> tc;
	while (tc--) {
		cin >> r >> c;
		vector<vector<int>> a(r, vector<int>(c, 1));
		for (int i = 1; i + 1 < r; i++) {
			for (int j = 1; j + 1 < c; j++) {
				a[i][j] = 0;
			}
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (a[i][j]) {
					for (int k = 0; k < 8; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (nx >= 0 and nx < r and ny >= 0 and ny < c) {
							a[nx][ny] = 0;
						}
					}
				}
				cout << a[i][j];
			}
			cout << "\n";
		}
		cout << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?)
	* DON'T GET STUCK ON ONE APPROACH
*/
