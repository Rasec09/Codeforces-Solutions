#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;

ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

int main() {
	optimizar_io

	int tc;
	ll n;
	
	cin >> tc;
	while (tc--) {
		cin >> n;
		ll _lcm1 = 1, ans = 0;
		for (ll i = 2; _lcm1 <= n; i++) {
			ll _lcm2 = lcm(_lcm1, i);
			ans += i * ((n / _lcm1) - (n / _lcm2));
			ans %= 1000000007;
			_lcm1 = _lcm2;
		}
		cout << ans << "\n";
	}
	return 0;
}
