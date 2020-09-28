#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, a, b;

	cin >> tc;
	while (tc--) {
		cin >> a >> b;
		int diff = abs(a - b);
		if (diff == 0) {
			cout << 0 << "\n";
			continue;
		}
		int ans = 0;
		for (int i = 10; i > 0; i--) {
			int d = diff / i;
			if (d > 0) {
				ans += d;
				diff -= d * i;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
