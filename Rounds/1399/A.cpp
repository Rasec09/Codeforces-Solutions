#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, n, a[55];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		bool possible = true;
		for (int i = 1; i < n; i++) {
			if (abs(a[i] - a[i - 1]) > 1) {
				possible = false;
				break;
			}
		}
		cout << (possible ? "YES\n" : "NO\n");
	}
	return 0;
}
