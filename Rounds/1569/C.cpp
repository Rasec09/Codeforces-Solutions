#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;
const ll mod = 998244353;

ll powMod(ll a, ll n, ll m) {
	ll result = 1;
	while (n) {
		if (n & 1)
			result = (result * a) % m;
		a = (a * a) % m;
		n >>= 1;
	}
	return result;
}

ll inv(ll a, ll p) {
	return powMod(a, p - 2, p);
}

int main() {
	optimizar_io
	int tc, n;
	array<int,200000> a;
	vector<ll> fac(200010);

	fac[0] = 1;
	for (int i = 1; i <= 200000; i++) {
		fac[i] = 1LL * i * fac[i - 1];
		fac[i] %= mod;
	}
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		map<int,int> freq;
		for (int i = 0; i < n; i++) freq[a[i]]++;
		auto it = freq.rbegin(); it++;
		if (freq.rbegin() -> second > 1) {
			cout << fac[n] << "\n";
		}
		else if ((it -> first) + 1 < freq.rbegin() -> first) {
			cout << "0\n";
		}
		else {
			// ans = (n! * k) / k + 1
			ll k = it -> second;
			ll ans = (fac[n] * k) % mod;
			ans = (ans * inv(k + 1, mod)) % mod;
			cout << ans << "\n";
		}
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
