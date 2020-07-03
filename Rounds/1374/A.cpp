#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll; 

int main() {
	optimizar_io
	int tc;
	ll x, y, n;

	cin >> tc;
	while (tc--) {
		cin >> x >> y >> n;
		ll d = n / x;
		ll ans = y + x * d;
		if (ans > n)
			ans -= x;
		cout << ans << "\n";
	}
	return 0;
}
