#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
 
int main() {
	optimizar_io
	int tc, a, b;

	cin >> tc;
	while (tc--) {
		cin >> a >> b;
		int d = abs(a - b) / 2; 
		a += b;
		vector<int> ans;
		if (a & 1) {
			for (int i = 0; i + d <= a - d; i++) {
				ans.push_back(d + i);
			}
		}
		else {
			for (int i = 0; i + d <= a - d; i += 2) {
				ans.push_back(d + i);
			}
		}
		cout << ans.size() << "\n";
		for (auto x : ans) cout << x << " ";
		cout << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
