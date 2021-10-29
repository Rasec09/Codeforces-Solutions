#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int solve(string &s, char c) {
	int cnt = 0, i = 0, j = int(s.size()) - 1;
	while (i < j) {
		if (s[i] == s[j]) {
			i++;
			j--;
		}
		else {
			if (s[i] == c) {
				i++;
				cnt++;
			}
			else if (s[j] == c) {
				j--;
				cnt++;
			}
			else {
				return numeric_limits<int>::max();
			}
		}
	}
	return cnt;
}

int main() {
	optimizar_io
	int tc, n;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> n >> s;
		int ans = numeric_limits<int>::max();
		for (char c = 'a'; c <= 'z'; c++) {
			ans = min(ans, solve(s, c));
		}
		if (ans == numeric_limits<int>::max())
			cout << "-1\n";
		else
			cout << ans << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
