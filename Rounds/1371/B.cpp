#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc; 
	ll n, r;

	cin >> tc;
	while (tc--) {
		cin >> n >> r;
		if (n == 1) {
			cout << n << "\n";
		}
		else if (n == 2) {
			cout << (r == 1 ? "1\n" : "2\n");
		}
		else {
			ll limit = min(n - 1, r);
			ll ans = (limit * (limit + 1)) / 2;
			if (r >= n)
				ans++;
			cout << ans << "\n"; 
		}
	}
	return 0;
}
