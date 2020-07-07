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
		for (int i = 0; i < n; i++) {
			if (i & 1) {
				if (a[i] > 0)
					a[i] *= -1;
			}
			else {
				if (a[i] < 0)
					a[i] *= -1;
			}
		}
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << "\n";
	}
	return 0;
}
