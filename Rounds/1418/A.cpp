#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc; 
	ll x, y, k;

	cin >> tc;
	while (tc--) {
		cin >> x >> y >> k;
		ll coal = y * k;
		ll sticks = k + coal;
		ll get = x - 1;
		ll ans = 0;
		if (get == 1)
			ans = sticks - 1;
		else {
			ans = sticks / get;
			if (ans * get + 1 < sticks)
				ans++;
		}
		ans += k;
		cout << ans << "\n";
	}
	return 0;
}
