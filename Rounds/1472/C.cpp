#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, n, a[200010], b[200010];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = n - 1; i >= 0; i--) {
			b[i] = a[i];
			if (i + a[i] < n)
				b[i] += b[i + a[i]];
		}
		cout << *max_element(b, b + n) << "\n";
	}
	return 0;
}
