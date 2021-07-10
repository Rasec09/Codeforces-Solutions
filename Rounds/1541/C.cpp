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
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a.begin(), a.begin() + n);
		ll total = 0;
		for (int i = 0; i < n; i++) total += a[i];
		ll ans = a[n - 1];
		for (int i = 0; i + 1 < n; i++) {
			total -= a[i];
			ans += (n - i - 1) * a[i] - total;
		}
		cout << ans << "\n";
	}
	return 0;
}
