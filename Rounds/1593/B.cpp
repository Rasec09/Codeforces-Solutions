#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int solve(string &s, string &end) {
	int n = int(s.size()) - 1;
	int r = -1;
	for (int i = n; i >= 0; i--) {
		if (s[i] == end[0]) {
			r = i;
			break;
		}
	}
	if (r == -1) return (1 << 30);
	int l = -1;
	for (int i = r - 1; i >= 0; i--) {
		if (s[i] == end[1]) {
			l = i;
			break;
		}
	}
	if (l == -1) return (1 << 30);
	int ans = n - r;
	ans += r - (l + 1);
	return ans;
}

int main() {
	optimizar_io
	int tc;
	string s;
	string end[4] = {"00", "52", "05", "57"};

	cin >> tc;
	while (tc--) {
		cin >> s;
		int ans = numeric_limits<int>::max();
		for (int i = 0; i < 4; i++) {
			ans = min(ans, solve(s, end[i]));
		}
		cout << ans << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
