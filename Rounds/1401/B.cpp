#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc;
	ll a[3], b[3];

	cin >> tc;
	while (tc--) {
		for (int i = 0; i < 3; i++) cin >> a[i];
		for (int j = 0; j < 3; j++) cin >> b[j];
		ll ans = 0, mn = min(a[2], b[1]);
		ans += 2 * mn;
		a[2] -= mn; b[1] -= mn;
		mn = min(a[1], b[0]);
		a[1] -= mn; b[0] -= mn;
		mn = min(a[0], b[2]);
		a[0] -= mn; b[2] -= mn;
		cout << ans - 2 * min(a[1], b[2]) << "\n";
	}
	return 0;
}
