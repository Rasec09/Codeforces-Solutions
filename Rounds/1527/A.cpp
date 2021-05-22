#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
    int tc, n;

	cin >> tc;
	while (tc--) {
		cin >> n;
		int ans = 1;
		while (ans <= n) {
			ans <<= 1;
		}
		ans >>= 1;
		cout << ans - 1 << "\n";
	}
	return 0;
}
