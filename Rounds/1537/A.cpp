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
		ll total = 0;
		for (int i = 0; i < n; i++) cin >> a[i], total += a[i];
		if (total < 0 or total < n) {
			cout << "1\n";
		}
		else {
			cout << total - n << "\n";
		}
	}
	return 0;
}
