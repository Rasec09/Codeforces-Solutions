#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;

int main() {
	optimizar_io
	int tc;
	ll n, k;

	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		if (n == 1) {
			cout << "0\n";
			continue;
		}
		if (k == 1) {
			cout << n - 1 << "\n";
			continue;
		}
		n -= 1;
		ll ans = 0, pot = 1;
		while (pot <= k) {
			if (n >= pot)
				n -= pot;
			else
				break;
			pot <<= 1;
			ans++;
		}
		if (n > 0) ans += (n + k - 1) / k;
		cout << ans << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
