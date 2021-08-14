#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int n, m, u, v, q, type;

	cin >> n >> m;
	vector<int> cnt(n); // cnt[i] = # of neigbours greater than i
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		u--; v--;
		cnt[min(u, v)]++;
	}
	int ans = count(cnt.begin(), cnt.end(), 0); // # of cnt[i] == 0
	cin >> q;
	while (q--) {
		cin >> type;
		if (type == 1) {
			cin >> u >> v;
			u--; v--;
			cnt[min(u, v)]++;
			if (cnt[min(u, v)] == 1)
				ans--;
		}
		else if (type == 2) {
			cin >> u >> v;
			u--; v--;
			cnt[min(u, v)]--;
			if (cnt[min(u, v)] == 0)
				ans++;
		}
		else {
			cout << ans << "\n";
		}
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
