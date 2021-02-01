#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
    int tc, n, k;
	ll p[105];

	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> p[i];
		ll ans = 0, sum = p[0];
		for (int i = 1; i < n; i++) {
			if (100 * p[i] > k * sum) {
				ll x = 0;
				ll l = 1, r = (1LL << 50);
				while (l < r) {
					ll m = l + (r - l) / 2;
					// cout << "m " << m << "\n";
					if (100 * p[i] <= k * (sum + m))
						r = m;
					else
						l = m + 1;
				}
				sum += l;
				ans += l;
			}
			sum += p[i];
		}
		cout << ans << "\n";
	}
	return 0;
}
