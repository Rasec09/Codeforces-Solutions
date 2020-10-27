#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
 
int main() {
	optimizar_io
	int tc, n, m, a[510][510];
 
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		map<int, int> idx;
		vector<vector<int>> rows;
		for (int i = 0; i < n; i++) {
			vector<int> r(m);
			for (int j = 0; j < m; j++) {
				cin >> r[j];
				idx[r[j]] = i;
			}
			rows.push_back(r);
		}
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];
		
		vector<vector<int>> ans;
		for (int j = 0; j < n; j++) {
			ans.push_back(rows[idx[a[0][j]]]);
		}
		for (int i = 0; i < ans.size(); i++) {
			for (int j = 0; j < ans[i].size(); j++)
				cout << ans[i][j] << " ";
			cout << "\n";
		}
	}
	return 0;
}
