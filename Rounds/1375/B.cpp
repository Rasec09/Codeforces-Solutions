#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
	optimizar_io
	int tc, n, m, a[305][305];

	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> a[i][j];
		bool valid = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int neighbours = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx >= 0 and nx < n and ny >= 0 and ny < m)
						neighbours++;
				}
				if (a[i][j] > neighbours) {
					cout << "NO\n";
					valid = false;
					break;
				}
				else {
					a[i][j] = neighbours;
				}
			}
			if (!valid)
				break;
		}
		if (valid) {
			cout << "YES\n";
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++)
					cout << a[i][j] << " ";
				cout << "\n";
			}
		}
	}
	return 0;
}
