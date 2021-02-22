#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
    int tc, n, m, p[200010];
	string s;

	cin >> tc;
	while (tc--) {
		cin >> n >> m >> s;
		for (int i = 0; i < m; i++) cin >> p[i];
		vector<vector<int>> cnt;
		cnt.assign(26, vector<int>(n, 0));
		for (int i = 0; i < n; i++) {
			cnt[s[i] - 'a'][i]++;
		}
		for (int i = 0; i < 26; i++) {
			for (int j = 1; j < n; j++)
				cnt[i][j] += cnt[i][j - 1];
		}
		/*for (int i = 0; i < cnt.size(); i++) {
			for (int j = 0; j < cnt[i].size(); j++) {
				cout << cnt[i][j] << " ";
			}
			cout << "\n";
		}*/
		vector<ll> ans(26);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < 26; j++) {
				ans[j] += cnt[j][p[i] - 1];
			}
		}
		for (int i = 0; i < 26; i++) {
			ans[i] += cnt[i][n - 1];
		}
		for (int x : ans)
			cout << x << " ";
		cout << "\n";
	}
	return 0;
}
