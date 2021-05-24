#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
    int tc, n, k1, k2, w, b;

	cin >> tc;
	while (tc--) {
		cin >> n >> k1 >> k2 >> w >> b;
		if (2 * w > k1 + k2) {
			cout << "NO\n";
		}
		else if (2 * b > 2 * n - (k1 + k2)) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
		}
	}
	return 0;
}
