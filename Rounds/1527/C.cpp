#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
    int tc, n, a[100010];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		map<int,vector<ll>> mp;
		for (int i = 0; i < n; i++) {
			mp[a[i]].push_back(i + 1);
		}
		ll ans = 0;
		for (auto &v : mp) {
			ll sum = 0;
			for (auto x : v.second) {
				ans += sum * (n - x + 1);
				sum += x;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
