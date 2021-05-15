#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
    int n, a[5010], b[5010];

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	ll total = 0;
	for (int i = 0; i < n; i++) total += 1LL * a[i] * b[i];
	ll ans = total;
	for (int c = 0; c < n; c++) {
		ll curr = total;
		for (int l = c - 1, r = c + 1; l >= 0 and r < n; l--, r++) {
			curr -= 1LL * a[l] * b[l];
			curr -= 1LL * a[r] * b[r];
			curr += 1LL * a[l] * b[r];
			curr += 1LL * a[r] * b[l];
			ans = max(ans, curr);
		}
		curr = total;
		for (int l = c, r = c + 1; l >= 0 and r < n; l--, r++) {
			curr -= 1LL * a[l] * b[l];
			curr -= 1LL * a[r] * b[r];
			curr += 1LL * a[l] * b[r];
			curr += 1LL * a[r] * b[l];
			ans = max(ans, curr);
		}
	}
	cout << ans << "\n";
	return 0;
}
