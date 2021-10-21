#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

void getDivisors(int x, set<int> &d) {
	for (int i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			d.insert(i);
			d.insert(x / i);
		}
	}
}

int main() {
	optimizar_io
	int tc, n;
	array<int,40> a;

	cin >> tc;
	while (tc--) {
		cin >> n;
		map<int,int> freq;
		for (int i = 0; i < n; i++) cin >> a[i], freq[a[i]]++;
		int m = (n + 1) / 2;
		bool ok = true;
		for (auto f : freq) {
			if (f.second >= m) {
				ok = false;
				break;
			}
		}
		if (!ok) {
			cout << "-1\n";
			continue;
		}
		set<int> div;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int diff = abs(a[i] - a[j]);
				getDivisors(diff, div);
			}
		}
		int ans = -1;
		for (auto d : div) {
			map<int,int> cnt;
			for (int i = 0; i < n; i++) {
				int mod = ((a[i] % d) + d) % d;
				cnt[mod]++;
				if (cnt[mod] >= m)
					ans = max(ans, d);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
