#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, n, a[200010];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		map<int,int> cnt;
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			int b = a[i] - i;
			if (cnt.count(b))
				ans += cnt[b];
			cnt[b]++;
		}
		cout << ans << "\n";
	}
	return 0;
}
