#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
    int tc, n, u, v, a[105];

	cin >> tc;
	while (tc--) {
		cin >> n >> u >> v;
		for (int i = 0; i < n; i++) cin >> a[i];
		int diff = -1;
		for (int i = 0; i + 1 < n; i++) {
			diff = max(diff, abs(a[i] - a[i + 1]));
		}
		if (diff >= 2) {
			cout << "0\n"; 
		}
		else if (diff == 1) {
			int ans = 1 << 30;
			for (int i = 0; i + 1 < n; i++) {
				int d = abs(a[i] - a[i + 1]);
				if (d) {
					ans = min({ans, u, v});
				}
				else {
					ans = min({ans, u + v, v + v});
				}
			}
			cout << ans << "\n";
		}
		else if (diff == 0) {
			cout << min(u + v, v + v) << "\n";
		}
	}
	return 0;
}
