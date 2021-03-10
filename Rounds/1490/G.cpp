#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
	
typedef long long int ll;
	
int main() {
	optimizar_io
	int tc, n, m, a[200010], x[200010];
	
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++) cin >> x[i];
		vector<ll> prefix;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i];
			if (i)
				prefix.push_back(max(prefix[i - 1], sum));
			else
				prefix.push_back(sum);
		}
		vector<ll> ans;
		for (int i = 0; i < m; i++) {
			if (sum <= 0) {
				if (prefix.back() < x[i]) {
					ans.push_back(-1);
				}
				else {
					int pos = lower_bound(prefix.begin(), prefix.end(), x[i]) - prefix.begin();
					ans.push_back(pos);
				}
			}
			else {
				ll vueltas = max(0LL, ((x[i] - prefix.back()) + sum - 1) / sum);
				int pos = lower_bound(prefix.begin(), prefix.end(), x[i] - sum * vueltas) - prefix.begin();
				ans.push_back(n * vueltas + pos);
			}
		}
		for (ll a : ans) cout << a << " ";
		cout << "\n";
	}
	return 0;
}
