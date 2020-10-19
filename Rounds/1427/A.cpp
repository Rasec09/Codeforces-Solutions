#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, n, a[55];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		int sum = 0, pos = 0, neg = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i];
			if (a[i] >= 0)
				pos += a[i];
			else
				neg += a[i];
		}
		neg *= -1;
		if (sum) {
			if (pos < neg) {
				sort(a, a + n);
			}
			else {
				sort(a, a + n, greater<int>());
			}
			cout << "YES\n";
			for (int i = 0; i < n; i++)
				cout << a[i] << " ";
			cout << "\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}
