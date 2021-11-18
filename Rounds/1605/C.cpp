#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;

bool isValid(string &s) {
	vector<int> cnt(3);
	for (int i = 0; i < s.size(); i++) 
		cnt[s[i] - 'a']++;
	return (cnt[0] > cnt[1] and cnt[0] > cnt[2]);
}

int main() {
	optimizar_io
	int tc, n;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> n >> s;
		n = s.size();
		int ans = numeric_limits<int>::max();
		for (int k = 2; k <= 10; k++) {
			bool ok = true;
			for (int i = 0; i + k <= s.size(); i++) {
				string sub = s.substr(i, k);
				// cout << sub << "\n";
				if (isValid(sub)) {
					ans = k;
					ok = false;
					break;
				}
			}
			if (!ok) break;
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
