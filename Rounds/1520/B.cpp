#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
    int tc, n;

	cin >> tc;
	while (tc--) {
		cin >> n;
		int cnt = 0;
		for (ll i = 1, j = 1; i <= n; i++) {
			if (i * j <= n) {
				cnt++;
			}
			else {
				break;
			}
			if (i == 9) {
				i = 0;
				j *= 10;
				j += 1;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
