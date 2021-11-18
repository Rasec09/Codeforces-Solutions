#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;

ll powMod(ll a, ll n) {
	ll result = 1;
	while (n) {
		if (n & 1)
			result = result * a;
		a = a * a;
		n >>= 1;
	}
	return result;
}

int main() {
	optimizar_io
	int tc, n, k;
	array<int,10> a;

	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		k++;
		for (int i = 0; i < n; i++) cin >> a[i], a[i] = powMod(10, a[i]);
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			 int cnt = k;
      		if (i + 1 < n) cnt = min(cnt, a[i + 1] / a[i] - 1);
      		ans += a[i] * 1LL * cnt;
      		k -= cnt;
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
