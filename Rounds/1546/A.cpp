#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, n;
	array<int,100> a, b;

	cin >> tc;
	while (tc--) {
		cin >> n;
		int sum1 = 0;
		for (int i = 0; i < n; i++) cin >> a[i], sum1 += a[i];
		int sum2 = 0;
		for (int i = 0; i < n; i++) cin >> b[i], sum2 += b[i];
		if (n == 1) {
			cout << (a[0] == b[0] ? "0" : "-1") << "\n";
			continue;
		}
		if (sum1 != sum2) {
			cout << "-1\n";
			continue;
		}
		vector<pair<int,int>> ans;
		for (int i = 0; i < n; i++) {
			while (a[i] != b[i]) {
				if (a[i] > b[i]) {
					a[i]--;
					for (int j = 0; j < n; j++) {
						if (a[j] < b[j]) {
							a[j]++;
							ans.push_back(make_pair(i + 1, j + 1));
							break;
						}
					}
				}
				else {
					a[i]++;
					for (int j = 0; j < n; j++) {
						if (a[j] > b[j]) {
							a[j]--;
							ans.push_back(make_pair(j + 1, i + 1));
							break;
						}
					}
				}
			}
		}
		cout << ans.size() << "\n";
		for (int i = 0; i < ans.size(); i++) cout << ans[i].first << " " << ans[i].second << "\n";
	}
	return 0;
}
