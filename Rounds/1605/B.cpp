#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
 
int main() {
	optimizar_io
	int tc, n;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> n >> s;
		if (is_sorted(s.begin(), s.end())) {
			cout << "0\n";
			continue;
		}
		string r = s;
		sort(r.begin(), r.end());
		vector<int> ans;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != r[i]) {
				ans.push_back(i + 1);
			}
		}
		cout << 1 << "\n" << ans.size();
		for (auto x : ans) cout << " " << x;
		cout << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
