#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, n, h[200010];
	
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> h[i];
		sort(h, h + n);
		if (n == 2) {
			cout << h[0] << " " << h[1] << "\n";
			continue;
		}
		int diff = 1e9;
		for (int i = 0; i + 1 < n; i++)
			diff = min(diff, abs(h[i] - h[i + 1]));
		int idx = -1;
		for (int i = 0; i + 1 < n; i++) {
			if (diff  == abs(h[i] - h[i + 1])) {
				idx = i;
				break;
			}
		}
		for (int i = idx + 1; i < n; i++) cout << h[i] << " ";
		for (int i = 0; i <= idx; i++) cout << h[i] << " ";
		cout << "\n";
	}
	return 0;
}
