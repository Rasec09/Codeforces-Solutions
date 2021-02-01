#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

bool isLucky(int x, int d) {
	while (x) {
		if (x % 10 == d)
			return true;
		x /= 10;
	}
	return false;
}

int main() {
	optimizar_io
    int tc, q, d, a[100010];

	cin >> tc;
	while (tc--) {
		cin >> q >> d;
		for (int i = 0; i < q; i++) cin >> a[i];
		for (int i = 0; i < q; i++) {
			int limit = a[i] / d;
			bool possible = false;
			for (int j = limit; j >= 0; j--) {
				int rem = a[i] - d * j;
				if (isLucky(rem, d)) {
					cout << "YES\n";
					possible = true;
					break;
				}
			}
			if (!possible) {
				cout << "NO\n";
			}
		}
	}
	return 0;
}
