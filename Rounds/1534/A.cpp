#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef vector<int> vi;
typedef pair<int,int> ii;

int n, m, dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
char a[55][55];
vector<vi> color;

bool bfs() {
	color.assign(n, vi(m, -1));
	queue<ii> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != '.') {
				q.push(ii(i, j));
				color[i][j] = (a[i][j] == 'R' ? 1 : 0);
			}
		}
	}
	if (q.empty()) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				color[i][j] = ((i + j) & 1 ? 1 : 0);
		}
	}
	while (!q.empty()) {
		ii u = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = u.first + dx[i];
			int ny = u.second + dy[i];
			if (nx >= 0 and nx < n and ny >= 0 and ny < m) {
				if (color[nx][ny] == -1) {
					color[nx][ny] = 1 - color[u.first][u.second];
					q.push(ii(nx, ny));
				}
				else if (color[nx][ny] == color[u.first][u.second])
					return false;
			}
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
		if (bfs()) {
			cout << "YES\n";
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << (color[i][j] == 1 ? "R" : "W");
				}
				cout << "\n";
			}
		}
		else {
			cout << "NO\n";
		}
	} 
	return 0;
}
