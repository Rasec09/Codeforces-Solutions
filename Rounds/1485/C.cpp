#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, x, y;

	cin >> tc;
	while (tc--) {
		cin >> x >> y;
		ll ans = 0;
		for (int r = 1; r * r <= 1e9; r++) {
			if (min(y, (x - r) / r) - r > 0) {
				ans += min(y, (x - r) / r) - r;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
