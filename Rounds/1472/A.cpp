#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, w, h, n;

	cin >> tc;
	while (tc--) {
		cin >> w >> h >> n;
		int cnt = 1;
		while (!(w & 1)) {
			w /= 2;
			cnt *= 2;
		}
		while (!(h & 1)) {
			h /= 2;
			cnt *= 2;
		}
		cout << (cnt >= n ? "YES\n" : "NO\n");
	}
	return 0;
}
