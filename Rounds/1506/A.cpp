#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
    int tc;
	ll n, m, x;

	cin >> tc;
	while (tc--) {
		cin >> n >> m >> x;
		x--;
		ll i = x % n;
		ll j = (x - i) / n;
		ll ans = i * m + j;
		cout << ++ans << "\n";
	}
	return 0;
}
