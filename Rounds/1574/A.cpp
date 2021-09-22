#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, n;
	string s = "()";

	vector<vector<string>> ans(50);
	for (int i = 1; i <= 50; i++) {
		for (int k = 1; k <= i; k++) {
			string tmp = "";
			for (int j = 1; j <= k; j++) {
				tmp += s;
			}
			for (int j = 1; j < i - k + 1; j++) {
				tmp.push_back(')');
			}
			reverse(tmp.begin(), tmp.end());
			for (int j = 1; j < i - k + 1; j++) {
				tmp.push_back('(');
			}
			reverse(tmp.begin(), tmp.end());
			// cout << tmp << "\n";
			ans[i - 1].push_back(tmp);
		}
	}
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cout << ans[n - 1][i] << "\n";
		}
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
