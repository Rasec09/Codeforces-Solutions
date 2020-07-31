#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, n, a[105];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		a[n] = a[n - 1];
		vector<string> ans;
		string tmp;
		for (int i = 0; i < a[0]; i++)
			tmp.push_back('a');
		if (tmp.empty()) tmp.push_back('a');
		ans.push_back(tmp);
		for (int i = 0; i < n; i++) {
			tmp = "";
			for (int j = 0; j < a[i]; j++)
				tmp.push_back(ans[i][j]);
			while (tmp.size() <= a[i + 1]) {
				tmp.push_back(((ans[i].back() - 'a') + 1) % 26 + 'a');
			}
			ans.push_back(tmp);
		}
		for (auto w : ans) {
			cout << w << "\n";
		}
	}
	return 0;
}
