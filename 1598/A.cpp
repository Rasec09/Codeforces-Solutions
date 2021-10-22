#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
int n, m;
bool visited[105][105];
char grid[105][105];

int bfs(int x, int y) {
    visited[x][y] = true;
    queue<pair<int,int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		pair<int,int> next = q.front();
		q.pop();
		if (next.first == n - 1 and next.second == m - 1) {
			return true;
		}
		for (int i = 0; i < 8; i++) {
			int nx = next.first + dx[i];
			int ny = next.second + dy[i];
			if (nx >= 0 and nx < n and ny >= 0 and ny < m and grid[nx][ny] != '1' and !visited[nx][ny]) {
				q.push(make_pair(nx,ny));
				visited[nx][ny] = true;
			}
    	}
	}
    return false;
}

int main() {
	optimizar_io
	int tc;

	n = 2;
	cin >> tc;
	while (tc--) {
		cin >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> grid[i][j];
				visited[i][j] = false;
			}
		}
		cout << (bfs(0, 0) ? "YES" : "NO") << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
