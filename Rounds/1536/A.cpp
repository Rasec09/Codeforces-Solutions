#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
    int tc, n, a[105];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		int mn = *min_element(a, a + n);
		int mx = *max_element(a, a + n);
		if (mn < 0) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n" << mx + 1 << "\n";
			for (int i = 0; i <= mx; i++)
				cout << i << " ";
			cout << "\n";
		}
	}
	return 0;
}
