#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;

ll sum(ll x) {
	ll ret = (x * (x + 1)) / 2;
	return ret;
}

int main() {
	optimizar_io
	int tc, n, x, t;

	cin >> tc;
	while (tc--) {
		cin >> n >> x >> t;
		ll d = t / x;
		ll dissatisfaction;
		if (n >= d)
			dissatisfaction = sum(d - 1) + (d * (n - d));
		else 
			dissatisfaction = sum(n - 1);
		cout << dissatisfaction << "\n";
	}
	return 0;
}
