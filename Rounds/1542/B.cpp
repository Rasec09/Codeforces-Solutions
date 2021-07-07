#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;

bool solve(ll a, ll b, ll n) {
	if (a == 1) {
		return ((n - 1) % b == 0);
	}
	ll p = 1;
	while (p <= n) {
		if ((n - p) % b == 0)
			return true;
		p *= a;
	}
	return false;
}

int main() {
	optimizar_io
	int tc, a, b, n;

	cin >> tc;
	while (tc--) {
		cin >> n >> a >> b;
		cout << (solve(a, b, n) ? "Yes" : "No") << "\n";
	}
	return 0;
}
