#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, n, a[1010];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<int> ans, used(n);
		int mx = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] > a[mx]) {
				mx = i;
			}
		}
		used[mx] = 1;
		ans.push_back(a[mx]);
		int gcd = ans[0];
		for (int i = 1; i < n; i++) {
			int idx = -1, mx = 0;
			for (int j = 0; j < n; j++) {
				if (!used[j]) {
					if (__gcd(gcd, a[j]) > mx) {
						mx = __gcd(gcd, a[j]);
						idx = j;
					}
				}
			}
			ans.push_back(a[idx]);
			used[idx] = 1;
			gcd = __gcd(gcd, a[idx]);
		}
		for (int i = 0; i < n; i++)
			cout << ans[i] << " ";
		cout << "\n";
	}
	return 0;
}
