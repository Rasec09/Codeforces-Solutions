#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

char grid[2010][2010];

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

int main() {
	optimizar_io
	int tc, n, m;

	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		int hashtags = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> grid[i][j];
				if (grid[i][j] == '#')
					hashtags++;
			}
		}
		ll ans = powMod(2, hashtags, 1e9 + 7);
		if (hashtags == n * m) ans--;
		cout << ans << "\n";
	}
	return 0;
}
