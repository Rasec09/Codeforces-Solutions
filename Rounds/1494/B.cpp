#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

bool solve(int n, int a[]) {
	for (int mask = 0; mask < (1 << 4); mask++) {
		int up = a[0], right = a[1], down = a[2], left = a[3];
		if (mask & (1 << 0)) {
			up--;
			left--;
		}
		if (mask & (1 << 1)) {
			up--;
			right--;
		}
		if (mask & (1 << 2)) {
			right--;
			down--;
		}
		if (mask & (1 << 3)) {
			down--;
			left--;
		}
		if (min({up, right, down, left}) >= 0 and max({up, left, down, right}) <= n - 2)
			return true;
	}
	return false;
}

int main() {
	optimizar_io
    int tc, n, lados[4];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < 4; i++) cin >> lados[i];
		cout << (solve(n, lados) ? "YES\n" : "NO\n");
	}
	return 0;
}
