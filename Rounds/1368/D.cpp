#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int n, a[200010];

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	for (int bit = 0; bit < 30; bit++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (!(a[i] & (1 << bit)))
				cnt++;
		}
		for (int i = 0; i < cnt; i++) {
			a[i] = a[i] & ~(1 << bit);
		}
		for (int i = cnt; i < n; i++) {
			a[i] = a[i] | (1 << bit);
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans += 1LL * a[i] * a[i];
	cout << ans << "\n";
	return 0;
}