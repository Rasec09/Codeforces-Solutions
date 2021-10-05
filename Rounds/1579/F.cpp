#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, n, d;
	array<int,2000000> a;

	cin >> tc;
	while (tc--) {
		cin >> n >> d;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) a[i + n] = a[i];
		int g = __gcd(n, d);
		int size = n / g;
		n *= 2;
		vector<int> visited(n);
		int ans = 0;
		for (int i = 0; i < g; i++) {
			if (!visited[i]) {
				int cnt = 0, pos = i;
				for (int j = 0; j < 2 * size; j++) {
					visited[pos] = true;
					if (a[pos] == 1) {
						cnt++;
						ans = max(ans, cnt);
					}
					else {
						cnt = 0;
					}
					pos = (pos + d) % n;
				}
				if (cnt >= size) {
					ans = -1;
					break;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
/*
9 1
1 0 0 1 0 1 0 1 1
*/
