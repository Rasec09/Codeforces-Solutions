#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, n;
	ll a[200010];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		ll ans = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] < a[i - 1])
				ans += a[i - 1] - a[i];
		}
		cout << ans << "\n";
	}
	return 0;
}
