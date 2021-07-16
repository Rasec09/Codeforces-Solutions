#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, n, m;
	vector<string> a, b;

	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		a.assign(n, "");
		for (int i = 0; i < n; i++) cin >> a[i];
		b.assign(n - 1, "");
		for (int i = 0; i + 1 < n; i++) cin >> b[i];
		vector<vector<int>> cnt(m, vector<int>(26));
		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < a[i].size(); j++) {
				cnt[j][a[i][j] - 'a']++;
			}
		}
		for (int i = 0; i < b.size(); i++) {
			for (int j = 0; j < b[i].size(); j++) {
				cnt[j][b[i][j] - 'a']--;
			}
		}
		string ans;
		for (int i = 0; i < cnt.size(); i++) {
			for (int j = 0; j < 26; j++) {
				if (cnt[i][j] == 1) {
					ans.push_back(j + 'a');
					break;
				}
			}
		}
		cout << ans << "\n" << flush;
	}
	return 0;
}
