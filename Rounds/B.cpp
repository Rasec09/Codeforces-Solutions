#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;
const ll mod = 1e9 + 7;

ll factorial(int n) {
	ll f = 1;
	for (int i = 1; i <= n; i++) {
		f = (f * i) % mod; 
	}
	return f;
}

int main() {
	optimizar_io
    int tc, n, a[200010];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		int x = a[0];
		for (int i = 1; i < n; i++) x &= a[i];
		ll cnt = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == x)
				cnt++;
		}
		ll ans = (cnt * (cnt - 1)) % mod;
		ans = (ans * factorial(n - 2)) % mod;
		cout << ans << "\n";
	}
	return 0;
}
