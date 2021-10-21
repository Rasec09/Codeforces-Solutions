#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
 
int main() {
	optimizar_io
	int tc, n;
	array<int,40> a;

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		int mn = *min_element(a.begin(), a.begin() + n);
		int ans = -1;
		for (int i = 0; i < n; i++) {
			if (a[i] != mn) {
				int d = a[i] - mn;
				if (ans == -1)
					ans = d;
				else
					ans = __gcd(ans, d);
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
