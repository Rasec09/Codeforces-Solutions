#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

bool superior(pair<array<int,5>,int> &a, pair<array<int,5>,int> &b) {
	int cnt = 0;
	for (int i = 0; i < 5; i++)
		if (a.first[i] < b.first[i])
			cnt++;
	return cnt >= 3;
}

int main() {
	optimizar_io
	int tc, n;
	vector<pair<array<int,5>,int>> a;

	cin >> tc;
	while (tc--) {
		cin >> n;
		a.assign(n, pair<array<int,5>,int>());
		for (int i = 0; i < n; i++) {
			a[i].second = i + 1;
			for (int j = 0; j < 5; j++)
				cin >> a[i].first[j];
		}
		if (n == 1) {
			cout << "1\n";
			continue;
		}
		sort(a.begin(), a.end(), superior);
		int cnt = 0;
		for (int i = 1; i < n; i++) {
			if (superior(a[0], a[i]))
				cnt++;
		}
		if (cnt == n - 1)
			cout << a[0].second << "\n";
		else
			cout << "-1\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
