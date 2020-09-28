#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef int ll;

ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}

int main() {
	optimizar_io
	int tc, n, a[100010], b[100010];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort(b, b + n);
		bool sorted = true;
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i]) {
				sorted = false;
				break;
			}
		}
		if (sorted) {
			cout << "YES\n";
			continue;
		}
		bool possible = true;
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i] and gcd(a[i], b[0]) != b[0]) {
				possible = false;
				break;
			}
		}
		cout << (possible ? "YES\n" : "NO\n");
	}
	return 0;
}
