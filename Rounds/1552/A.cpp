#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, k;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> k >> s;
		string t = s;
		sort(t.begin(), t.end());
		int ans = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != t[i])
				ans++;
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
