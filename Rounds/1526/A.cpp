#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, n, a[55];

	cin >> tc;
	while (tc--) {
		cin >> n;
		n *= 2;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		vector<int> ans(n);
		int j = 0;
		for (int i = 0; i < n; i += 2, j++) {
			ans[i] = a[j];
		}
		for (int i = 1; i < n; i += 2, j++) {
			ans[i] = a[j];
		}
		for (auto x : ans) cout << x << " ";
		cout << "\n";
	}
	return 0;
}
