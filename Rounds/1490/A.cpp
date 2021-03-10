#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, n, a[50];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		int ans = 0;
		for (int i = 0; i + 1 < n; i++) {
			int mx = max(a[i], a[i + 1]);
			int mn = min(a[i], a[i + 1]);
			if ((mx + mn - 1) / mn > 2) {
				int cnt = 0;
				while ((mx + mn - 1) / mn > 2) {
					mx = (mx + 1) / 2;
					cnt++;
				}
				ans += cnt;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
