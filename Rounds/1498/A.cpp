#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}

ll gcdSum(ll x) {
	ll y = 0, _x = x;
	while (_x) {
		y += _x % 10;
		_x /= 10;
	}
	return gcd(x, y);
}

int main() {
	optimizar_io
    int tc;
	ll x;

	cin >> tc;
	while (tc--) {
		cin >> x;
		ll ans = x;
		for (; gcdSum(ans) == 1; ans++);
		cout << ans << "\n";
	}
	return 0;
}
