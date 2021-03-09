#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
    int tc, n, x[1010], y[1010];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
		if (n & 1) {
			cout << "1\n";
			continue;
		}
		sort(x, x + n);
		sort(y, y + n);
		ll numX = x[(n / 2)] - x[(n / 2) - 1] + 1;
		ll numY = y[(n / 2)] - y[(n / 2) - 1] + 1;
		cout << numX * numY << "\n";
	}
	return 0;
}
