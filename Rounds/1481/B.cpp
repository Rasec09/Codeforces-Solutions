#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, n, k, h[110];

	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> h[i];
		int cnt = 0, idx;
		while (true) {
			cnt++;
			idx = -1;
			for (int i = 0; i + 1 < n; i++) {
				if (h[i] < h[i + 1]) {
					h[i]++;
					idx = i + 1;
					break;
				}
			}
			if (idx == -1 or cnt == k) {
				break;
			}
		}
		cout << idx << "\n";
	}
	return 0;
}
