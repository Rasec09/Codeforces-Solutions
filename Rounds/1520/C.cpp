#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, n, matrix[105][105];

	cin >> tc;
	while (tc--) {
		cin >> n;
		int ROW = n, COL = n;
		if (n == 2) {
			cout << -1 << "\n";
			continue;
		}
		int x = 1;
		for (int line = 1; line <= (ROW + COL -1); line++) {
			int start_col =  max(0, line-ROW);
			int count = min({line, (COL-start_col), ROW});
			if (line & 1) {
				for (int j = 0; j < count; j++) {
					matrix[min(ROW, line)-j-1][start_col+j] = x++;
				}
			}
		}
		for (int line = 1; line <= (ROW + COL -1); line++) {
			int start_col =  max(0, line-ROW);
			int count = min({line, (COL-start_col), ROW});
			if (!(line & 1)) {
				for (int j = 0; j < count; j++) {
					matrix[min(ROW, line)-j-1][start_col+j] = x++;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << matrix[i][j] << " ";
			cout << "\n";
		}
	}
	return 0;
}
