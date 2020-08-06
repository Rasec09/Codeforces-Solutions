#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, n; 
	ll a[55], b[55];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		ll candy = *min_element(a, a + n);
		ll oranges = *min_element(b, b + n);
		ll cnt = 0;
		for (int i = 0; i < n; i++) {
			ll op = 0;
			if (a[i] > candy and b[i] > oranges) {
				op = min(a[i] - candy, b[i] - oranges);
				a[i] -= op;
				b[i] -= op;
				cnt += op;
			}
			if (a[i] > candy and b[i] == oranges) {
				op = a[i] - candy;
				a[i] -= op;
				cnt += op;
			}
			else if (a[i] == candy and b[i] > oranges) {
				op = b[i] - oranges;
				b[i] -= op;
				cnt += op;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
