#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
    int tc, n, a[5010];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		map<int,vector<int>> colors;
		for (int i = 0; i < n; i++) {
			colors[a[i]].push_back(i + 1);
		}
		if (colors.size() == 1) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		vector<vector<int>> v;
		for (auto c : colors) {
			v.push_back(c.second);
		}
		for (int i = 1; i < v.size(); i++) {
			for (int j = 0; j < v[i].size(); j++) {
				cout << v[0][0] << " " << v[i][j] << "\n";
			}			
		}
		for (int i = 1; i < v[0].size(); i++) {
			cout << v[1][0] << " " << v[0][i] << "\n";
		}
	}
	return 0;
}
