#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef vector<int> vi;

int main() {
	optimizar_io
	int tc, n, k;
	array<int,200010> a;

	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> a[i];
		map<int,vi> freq;
		for (int i = 0; i < n; i++) freq[a[i]].emplace_back(i);
		vector<vi> colors(k);
		int idx = 0;
		for (auto &[val, pos] : freq) {
			if (pos.size() >= k) {
				for (int i = 0; i < k; i++) {
					colors[i].push_back(pos.back());
					pos.pop_back();
				}
			}
			else {
				while (!pos.empty()) {
					colors[idx].push_back(pos.back());
					pos.pop_back();
					idx++;
					idx %= k;
				}
			}
		}
		int size = n;
		for (int i = 0; i < colors.size(); i++) {
			size = min(size, int(colors[i].size()));
		}
		for (int i = 0; i < colors.size(); i++) {
			while (colors[i].size() > size)
				colors[i].pop_back();
		}
		vi ans(n);
		for (int i = 0; i < colors.size(); i++) {
			for (int j = 0; j < colors[i].size(); j++)
				ans[colors[i][j]] = i + 1;
		}
		for (auto x : ans) cout << x << " ";
		cout << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
