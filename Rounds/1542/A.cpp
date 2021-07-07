#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
int main() {
	optimizar_io
	int tc, n;
	array<int,200> a;

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < 2 * n; i++) cin >> a[i];
		int even = 0, odd = 0;
		for (int i = 0; i < 2 * n; i++) {
			if (a[i] & 1)
				odd++;
			else
				even++;
		}
		cout << (even == n and odd == n ? "Yes" : "No") << "\n";
	}
	return 0;
}
