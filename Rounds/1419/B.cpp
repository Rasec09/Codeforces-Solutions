#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

ll gauss(ll x) {
	return (x * (x + 1)) / 2;
}

int main() {
	optimizar_io
	int tc;
	ll n;
	vector<ll> stair;

	for (ll i = 1; true; i++) {
		ll x = (1LL << i) - 1;
		x = gauss(x);
		if (x > 1e18) break;
		stair.push_back(x);
	}
	//for (auto x : stair)
	//	cout << x << "\n";
	cin >> tc;
	while (tc--) {
		cin >> n;
		int i;
		for (i = 0; i < stair.size(); i++) {
			if (n >= stair[i]) {
				n -= stair[i];
			}
			else {
				break;
			}
		}
		cout << i << "\n";
	}
	return 0;
}
