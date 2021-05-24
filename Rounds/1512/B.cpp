#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef pair<int,int> ii;

char grid[405][405];

int main() {
	optimizar_io
    int tc, n;

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cin >> grid[i][j];
		}
		vector<ii> v;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == '*')
					v.push_back(ii(i, j));
			}
		}
		if (v[0].first == v[1].first) {
			if (v[0].first + 1 < n) {
				grid[v[0].first + 1][v[0].second] = '*';
				grid[v[1].first + 1][v[1].second] = '*';
			}
			else {
				grid[v[0].first - 1][v[0].second] = '*';
				grid[v[1].first - 1][v[1].second] = '*';				
			}
		}
		else if (v[0].second == v[1].second) {
			if (v[0].second + 1 < n) {
				grid[v[0].first][v[0].second + 1] = '*';
				grid[v[1].first][v[1].second + 1] = '*';
			}	
			else {
				grid[v[0].first][v[0].second - 1] = '*';
				grid[v[1].first][v[1].second - 1] = '*';
			}
		}
		else {
			grid[v[0].first][v[1].second] = '*';
			grid[v[1].first][v[0].second] = '*';
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << grid[i][j];
			cout << "\n";
		}
	}
	return 0;
}
