#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
int main() {
	optimizar_io
	int tc;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> s;
		int ans = 1e9;
		for (int i = 0; i < (1 << 10); i++) {
			bool flag = true;
			for (int j = 0; j < 10; j++) {
				if (s[j] == '?') continue;
				int bit = i & (1 << j);
				if (s[j] - '0' == 0 and bit != 0) {
					flag = false;
					break;
				}
				if (s[j] -'0' == 1 and bit == 0) {
					flag = false;
					break;
				}
			}
			if (!flag) continue;
			// cout << i << "\n";
			int teamA = 0, teamB = 0;
			for (int j = 0; j < 10; j++) {
				if (i & (1 << j)) {
					if (j & 1)
						teamB++;
					else
						teamA++;
				}

				int tryA = 0, tryB = 0;
				for (int k = j + 1; k < 10; k++) {
					if (k & 1)
						tryB++;
					else
						tryA++;
				}

				if (teamA > teamB + tryB) {
					ans = min(ans, j);
					break;
				}
				if (teamB > teamA + tryA) {
					ans = min(ans, j);
					break;
				}
			}
		}
		cout << min(ans + 1, 10) << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
