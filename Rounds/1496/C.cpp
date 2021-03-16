#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, n;

	cin >> tc;
	while (tc--) {
		cin >> n;
		int x, y;
		vector<int> miners, diamonds;
		for (int i = 0; i < 2 * n; i++) {
			cin >> x >> y;
			if (x == 0)
				miners.push_back(abs(y));
			else
				diamonds.push_back(abs(x));
		}
		sort(miners.begin(), miners.end());
		sort(diamonds.begin(), diamonds.end());
		double ans = 0;
		for (int i = 0; i < miners.size(); i++) {
			ans += hypot(diamonds[i], miners[i]);
		}
		cout << fixed;
		cout << setprecision(12) << ans << "\n";
	}
	return 0;
}
