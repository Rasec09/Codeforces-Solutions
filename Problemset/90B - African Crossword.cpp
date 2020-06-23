#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int n, m;
	string s[105];
	vector<vector<bool>> visited;

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];
	visited.assign(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++) {
		vector<int> cnt(26);
		for (int j = 0; j < m; j++) {
			cnt[s[i][j] - 'a']++;
		}
		for (int j = 0; j < m; j++) {
			if (cnt[s[i][j] - 'a'] > 1)
				visited[i][j] = true;
		}
	}
	for (int j = 0; j < m; j++) {
		vector<int> cnt(26);
		for (int i = 0; i < n; i++) {
			cnt[s[i][j] - 'a']++;
		}
		for (int i = 0; i < n; i++) {
			if (cnt[s[i][j] - 'a'] > 1)
				visited[i][j] = true;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (!visited[i][j])
				cout << s[i][j];
	}
	cout << "\n";
	return 0;
}
