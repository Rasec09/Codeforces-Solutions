#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, n, a[100010];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		int j = upper_bound(a, a + n, 0) - a;
		if (j == n) {
			cout << n << "\n";
			continue;
		}
		int minPos = a[j], ans = j;
		bool flag = true;
		for (int i = 0; i + 1 < j; i++) { 
			if (abs(a[i] - a[i + 1]) < minPos) {
				flag = false;
				break;
			}
		}
		if (flag) ans++;
		cout << ans << "\n";
	}
	return 0;
}
