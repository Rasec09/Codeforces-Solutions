#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int n, m, a[200010];

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	if (n > m)
		cout << "0\n";
	else {
		int ans = 1;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				ans = (ans % m) * (abs(a[i] - a[j]) % m);
				ans %= m;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
