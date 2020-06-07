#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int n, m, a[55][55];

bool isUnclaimed(int x, int y) {
	if (a[x][y] == 1) return false;
	for (int j = 0; j < m; j++) {
		if (a[x][j] == 1) {
			return false;
		}
	}
	for (int j = 0; j < n; j++) {
		if (a[j][y] == 1) {
			return false;
		}
	}
	return true;
}

int main() {
	optimizar_io
	int tc;

	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cin >> a[i][j];
		}
		int freeRows = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (isUnclaimed(i, j)) {
					freeRows++;
					break;
				}
			}
		}
		int freeCols = 0;
		for (int j = 0; j < m; j++) {
			for (int i = 0; i < n; i++) {
				if (isUnclaimed(i, j)) {
					freeCols++;
					break;
				}
			}
		}
		cout << (min(freeRows, freeCols) & 1 ? "Ashish\n" : "Vivek\n");
	}
	return 0;
}
