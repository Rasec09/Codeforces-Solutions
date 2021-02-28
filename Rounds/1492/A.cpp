#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
    int tc;
	ll p, a, b, c;

	cin >> tc;
	while (tc--) {
		cin >> p >> a >> b >> c;
		if (p % a == 0 or p % b == 0 or p % c == 0) {
			cout << "0\n";
			continue;
		}
		ll a1 = p / a;
		ll b1 = p / b;
		ll c1 = p / c;
		ll ans = min({abs(p - a * (a1 + 1)), 
					abs(p - b * (b1 + 1)),
					abs(p - c * (c1 + 1))});
		cout << ans << "\n";
	}
	return 0;
}
