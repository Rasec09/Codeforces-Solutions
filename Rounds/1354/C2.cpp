#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

double PI = acos(-1);

double degreeToRad(double angle) {
	return angle * PI / 180.0;
}

int main() {
    optimizar_io
	int tc, n; 

	cin >> tc;
	while (tc--) {
		cin >> n;
		double ans = cos(degreeToRad(180.0 / (4.0 * n))) / sin(degreeToRad(180.0 / (2.0 * n)));
		cout << fixed;
		cout << setprecision(9) << ans << "\n";
	}
    return 0;
}
