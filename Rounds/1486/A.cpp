#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
    int tc, n, a[105];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		ll sum = a[0];
		a[0] = 0;
		bool possible = true;
		for (int i = 1; i < n; i++) {
			if (a[i] >= i) {
				sum += a[i] - i;
				a[i] = i;
			}
			else {
				if (sum >= i - a[i]) {
					sum -= i - a[i];
					a[i] = i;
				}
				else {
					possible = false;
					break;
				}
			}
		}
		// for (int i = 0; i < n; i++) cout << a[i] << " ";
		// cout << "\n";
		cout << (possible ? "YES\n" : "NO\n"); 
	}
	return 0;
}
