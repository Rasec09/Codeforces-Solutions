#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;

int main() {
	optimizar_io
	int tc, n; 
	ll k;
	array<ll,100000> a;

	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> a[i];
		ll ans = -1e9;
		for (ll i = max(1LL, n - 2 * k); i <= n; i++) {
			for (ll j = i + 1; j <= n; j++)
				ans = max(ans, (i * j) - k * (a[i - 1] | a[j - 1]));
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
