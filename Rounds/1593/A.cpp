#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
 
int main() {
	optimizar_io
	int tc, a, b, c;

	cin >> tc;
	while (tc--) {
		cin >> a >> b >> c;
		vector<int> ans(3);
		if (a <= b or a <= c) {
			ans[0] = max(b, c) - a + 1;
		}
		if (b <= a or b <= c) {
			ans[1] = max(a, c) - b + 1;
		}
		if (c <= a or c <= b) {
			ans[2] = max(a, b) - c + 1;
		}
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
