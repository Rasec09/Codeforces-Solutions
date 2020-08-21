#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, n, a[200010];
	ll k;

	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> a[i];
		int mx = *max_element(a, a + n);
		for (int i = 0; i < n; i++)
			a[i] = mx - a[i];
		if (k & 1) {
			for (int i = 0; i < n; i++)
				cout << a[i] << " ";
			cout << "\n";
		}
		else {
			mx = *max_element(a, a + n);
			for (int i = 0; i < n; i++) {
				a[i] = mx - a[i];
				cout << a[i] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
