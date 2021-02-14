#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int n, q, k, l, r, a[100010];

	cin >> n >> q >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> cnt(n);
	cnt[0] = a[1] - 1;
	for (int i = 1; i + 1 < n; i++) {
		cnt[i] = a[i + 1] - a[i - 1] - 1;
	}
	cnt[n - 1] = k - a[n - 2];
	vector<ll> acum(n);
	acum[0] = cnt[0];
	for (int i = 1; i < n; i++) {
		acum[i] = cnt[i];
		acum[i] += acum[i - 1];
	}
	while (q--) {
		cin >> l >> r;
		l--; r--;
		if (l == r) {
			cout << k - 1 << "\n";
			continue; 
		}
		ll ans = 0;
		if (r - l + 1 > 2) {
			int l1 = l + 1, r1 = r - 1;
			ans += acum[r1] - acum[l1 - 1];
			ans -= r1 - l1 + 1;
		}
		ans += a[l + 1] - 1;
		ans += k - a[r - 1];
		ans -= 2;
		cout << ans << "\n";
	}
	return 0;
}
