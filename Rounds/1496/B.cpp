#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

bool isSorted(int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] != i)
			return false;
	}
	return true;
}

int main() {
	optimizar_io
	int tc, n, k, a[100010];

	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> a[i];
		if (k == 0) {
			cout << n << "\n";
			continue;
		}
		sort(a, a + n);
		if (isSorted(a, n)) {
			cout << n + k << "\n";
		}
		else {
			int mex = -1, mx = *max_element(a, a + n);
			for (int i = 0; i < n; i++) {
				if (a[i] != i) {
					mex = i;
					break;
				}
			}
			int x = (mx + mex + 1) / 2;
			auto it = find(a, a + n, x);
			if (it != a + n)
				cout << n << "\n";
			else
				cout << n + 1 << "\n";
		}
	}
	return 0;
}
