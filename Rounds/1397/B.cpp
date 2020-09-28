#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
	
typedef long long int ll;
const ll INF = (1LL << 60);

ll mod(ll a, ll b) {
	return ((a % b) + b) % b;
}

ll powMod(ll a, ll n, ll m) {
	ll result = 1;
	while (n) {
		if (n & 1)
			result = mod(result * a, m);
		a = mod(a * a, m);
		n >>= 1;
	}
	return result;
}

ll diff(ll a[], int n, ll x) {
	ll res = 0;
	for (int i = 0; i < n; i++) {
		res += llabs(powMod(x, i, INF) - a[i]);
		if (res < 0) return -1;
	}
	return res;
}
	
int main() {
	optimizar_io
	int n;
	ll a[100010];
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	ll ans = numeric_limits<ll>::max();
	for (ll x = 1; x <= 31623; x++) {
		ll mn = diff(a, n, x); 
		if (mn < ans && mn >= 0) {
			ans = mn;
		}
		else {
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
