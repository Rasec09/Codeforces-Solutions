#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, a, b, c, m;

	cin >> tc;
	while (tc--) {
		cin >> a >> b >> c >> m;
		int tmp = a ^ b ^ c;
		int _a = min({a, b, c});
		int _c = max({a, b, c});
		int _b = tmp ^ _a ^ _c;
		if (m <= (_a + _b + _c - 3) and m >= _c - (_a + _b + 1))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
