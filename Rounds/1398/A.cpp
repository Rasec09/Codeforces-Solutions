#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, n, a[50010];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		if (a[0] + a[1] > a[n - 1] and a[1] + a[n - 1] > a[0] and a[0] + a[n - 1] > a[1])
			cout << "-1\n";
		else
			cout << "1 2 " << n << "\n";
	}
	return 0;
}
