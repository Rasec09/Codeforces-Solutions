#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int n, p, a[2010];

	cin >> n >> p;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	vector<int> ans;
	for (int x = a[n - 1] - n + 1; x < a[n - 1]; x++) {
		int rem = 1;
		for (int i = 0; i < n; i++) {
			int idx = upper_bound(a, a + n, x + i) - a;
			rem = (rem * (idx - i)) % p;
		}
		if (rem)
			ans.push_back(x);
	}
	cout << ans.size() << "\n";
	for (auto _a : ans)
		cout << _a << " ";
	cout << "\n";
	return 0;
}
