#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
 
int main() {
	optimizar_io
	int tc, n;
	array<ll,100000> a;

	cin >> tc;
	while (tc--) {
		cin >> n;
		ll total = 0;
		for (int i = 0; i < n; i++) cin >> a[i], total += a[i];
		sort(a.begin(), a.begin() + n);
		double ans;
		ll prefix = 0;
		for (int i = 0; i < n; i++) {
			prefix += a[i];
			if (i)
				ans = max(ans, (prefix / (i + 1.0)) + ((total - prefix) / (n - i - 1.0)));
			else
				ans = (prefix / (i + 1.0)) + ((total - prefix) / (n - i - 1.0));
		}
		cout << fixed << setprecision(9) << ans << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
