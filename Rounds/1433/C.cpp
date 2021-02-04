#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, n, a[300010];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		int mx = *max_element(a, a + n), ans = -1;
		for (int i = 1; i + 1 < n; i++) {
			if (a[i] == mx and (a[i] > a[i - 1] or a[i] > a[i + 1])) {
				ans = i + 1;
				break;
			}
		}
		if (a[0] == mx and a[0] > a[1])
			ans = 1;
		if (a[n - 1] == mx and a[n - 1] > a[n - 2])
			ans = n;
		cout << ans << "\n";
	}
	return 0;
}
