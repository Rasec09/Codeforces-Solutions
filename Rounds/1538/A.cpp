#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, n, a[105];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		int mn = min_element(a, a + n) - a;
		int mx = max_element(a, a + n) - a;
		int cnt1 = 0;
		for (int i = 0; i <= max(mn, mx); i++) {
			cnt1++;
		}
		int cnt2 = 0;
		for (int i = n - 1; i >= min(mx, mn); i--) {
			cnt2++;
		}
		int cnt3 = 0;
		for (int i = 0; i <= min(mn, mx); i++) {
			cnt3++;
		}
		for (int i = n - 1; i >= max(mx, mn); i--) {
			cnt3++;
		}
		cout << min({cnt1, cnt2, cnt3}) << "\n";
	}
	return 0;
}
