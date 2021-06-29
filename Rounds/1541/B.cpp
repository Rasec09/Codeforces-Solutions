#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
 
int main() {
	optimizar_io
	int tc, n, a[200010];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		map<int,int> nums;
		for (int i = 0; i < n; i++) nums[a[i]] = i + 1;
		ll ans = 0;
		for (int x = 1; x <= 2 * n; x++) {
			for (int d = 1; d * d <= x; d++) {
				if (x % d == 0 and d != x / d) {
					if (nums.count(d) and nums.count(x / d) and nums[d] + nums[x / d] == d * (x / d))
						ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
