#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
    int tc, n, a[400010];

	cin >> tc;
	while (tc--) {
		cin >> n;
		ll ans = 0;
		for (int i = 0; i < n; i++) cin >> a[i], ans += a[i];
		ll cost = 0;
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				if (a[0] > a[1]) {
					cost += a[0] - a[1];
					a[0] = a[1];
				}
			}
			else if (i == n - 1) {
				if (a[n - 1] > a[n - 2]) {
					cost += a[n - 1] - a[n - 2];
					a[n - 1] = a[n - 2];
				}
			}
			else if (a[i] > a[i - 1] and a[i] > a[i + 1]) {
				cost += min(a[i] - a[i - 1], a[i] - a[i + 1]);
				a[i] = max(a[i - 1], a[i + 1]);
			}
		}
		cost += a[0] + a[n - 1];
		for (int i = 0; i + 1 < n; i++) {
			cost += abs(a[i] - a[i + 1]);
		}
		ans = min(ans, cost);
		cout << ans << "\n";
	}
	return 0;
}
