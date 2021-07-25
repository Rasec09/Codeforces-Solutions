#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, n;

	cin >> tc;
	while (tc--) {
		cin >> n;
		int x1 = n / 3;
		int x2 = (n + 2) / 3;
		if ((abs((n - (2 * x1)) - x1)) <= (abs((n - (2 * x2)) - x2)))
			cout << (n - (2 * x1)) << " " << x1 << "\n";
		else
			cout << (n - (2 * x2)) << " " << x2 << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
