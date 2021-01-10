#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

bool iguales(double a, double b) {
	return fabs(a - b) < 1e-9;
}

int main() {
	optimizar_io
	int tc, n, a[55];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<double> areas;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				double x = hypot(0 - a[i], 1 - 0);
				double y = hypot(0 - a[j], 1 - 0);
				double z = hypot(a[i] - a[j], 0 - 0);
				if (x + y > z and x + z > y and y + z > x) {
					double s = (x + y + z) / 2.0;
					double area = s * (s - x) * (s - y) * (s - z);
					area = sqrt(area);
					if (area > 0)
						areas.push_back(area);
				}
			}
		}
		sort(areas.begin(), areas.end());
		/*for (int i = 0; i < areas.size(); i++) {
			cout << fixed;
			cout << setprecision(9) << areas[i] << "\n";
		}*/
		vector<double> ans;
		for (int i = 0; i < areas.size(); i++) {
			bool exist = false;
			for (int j = 0; j < ans.size(); j++) {
				exist |= iguales(ans[j], areas[i]);
			}
			if (!exist)
				ans.push_back(areas[i]);
		}
		cout << ans.size() << "\n";
	}
	return 0;
}
