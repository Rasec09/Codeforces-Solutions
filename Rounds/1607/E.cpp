#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
 
int main() {
	optimizar_io
	int tc, n, m;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> n >> m >> s;
		int dx = 0, dy = 0, minDx = 0, maxDx = 0, minDy = 0, maxDy = 0, x = 1, y = 1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'L') dy--;
			if (s[i] == 'R') dy++;
			if (s[i] == 'U') dx--;
			if (s[i] == 'D') dx++;
			minDx = min(minDx, dx);
			maxDx = max(maxDx, dx);
			minDy = min(minDy, dy);
			maxDy = max(maxDy, dy);
			// x + maxDx <= n
			// x + minDx >= 1
			int minX = 1 - minDx;
			int maxX = n - maxDx;
			int minY = 1 - minDy;
			int maxY = m - maxDy;
			if (minX <= maxX and minY <= maxY) {
				x = minX;
				y = minY;
			}
		}
		cout << x << " " << y << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
