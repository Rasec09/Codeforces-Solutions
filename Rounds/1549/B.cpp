#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, n;
	string a, b;

	cin >> tc;
	while (tc--) {
		cin >> n >> a >> b;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (b[i] == '1') {
				if (a[i] == '0') {
					ans++;
					a[i] = '2';
				}
				else if (i - 1 >= 0 and a[i - 1] == '1') {
					ans++;
					a[i - 1] = '2';
				}
				else if (i + 1 < n and a[i + 1] == '1') {
					ans++;
					a[i + 1] = '2';
				}
			}
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
