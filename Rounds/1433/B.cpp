#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
   int tc, n;

	cin >> tc;
	while (tc--) {
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		int l = -1, r = n;
		for (int i = 0; i < n; i++) {
			if (a[i] == 1) {
				l = i;
				break;
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			if (a[i] == 1) {
				r = i;
				break;
			}
		}
		int ans = 0;
		for (int i = l; i <= r; i++) {
			if (a[i] == 0)
				ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}
