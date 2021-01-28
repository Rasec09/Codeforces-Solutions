#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int a[200010], b[200010];

int main() {
	optimizar_io
    int tc, n;
	ll m;

	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		vector<ll> regular, important;
		for (int i = 0; i < n; i++) {
			if (b[i] == 1)
				regular.push_back(a[i]);
			else
				important.push_back(a[i]);
		}
		sort(regular.begin(), regular.end(), greater<int>());
		sort(important.begin(), important.end(), greater<int>());
		for (int i = 1; i < regular.size(); i++) regular[i] += regular[i - 1];
		for (int i = 1; i < important.size(); i++) important[i] += important[i - 1];
		/*
		for (auto x : regular) cout << x << " ";
		cout << "\n";
		for (auto x : important) cout << x << " ";
		cout << "\n";
		*/
		if (regular.empty()) {
			if (m > important.back()) 
				cout << "-1\n";
			else {
				int j = (lower_bound(important.begin(), important.end(), m) - important.begin());
				cout << (j + 1) * 2 << "\n";
			}
			continue;
		}
		if (important.empty()) {
			if (m > regular.back())
				cout << "-1\n";
			else {
				int j = (lower_bound(regular.begin(), regular.end(), m) - regular.begin());
				cout << (j + 1) << "\n";
			}
			continue;
		}
		if (m > regular.back() + important.back()) {
			cout << "-1\n";
			continue;
		}
		int ans = numeric_limits<int>::max();
		if (m <= regular.back()) {
			int j = (lower_bound(regular.begin(), regular.end(), m) - regular.begin());
			ans = min(ans, (j + 1));
		}
		if (m <= important.back()) {
			int j = (lower_bound(important.begin(), important.end(), m) - important.begin());
			ans = min(ans, (j + 1) * 2);
		}
		for (int i = 0; i < regular.size(); i++) {
			ll x = m - regular[i];
			if (x < 0) break;
			int j = (lower_bound(important.begin(), important.end(), x) - important.begin());
			// cout << "(" << i << "," << j << ") " << ((i + 1) + (j + 1) * 2) << "\n";
			if (j == important.size()) continue;
			ans = min(ans, (i + 1) + (j + 1) * 2);
		}
		cout << ans << "\n";
	}
	return 0;
}
