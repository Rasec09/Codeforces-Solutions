#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, n, a[45];

	cin >> tc;
	while (tc--) {
		cin >> n;
		int par = 0, impar = 0, diff = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] & 1)
				impar++;
			else
				par++;
			if (a[i] % 2 != i % 2)
				diff++;
		}
		if (par > (n + 1) / 2 or impar > n / 2) {
			cout << "-1\n";
			continue;
		}
		cout << diff / 2 << "\n";
	}
	return 0;
}
