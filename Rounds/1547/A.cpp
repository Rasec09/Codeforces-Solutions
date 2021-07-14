#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
#define x first
#define y second

typedef pair<int,int> ii;

int distance(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
	optimizar_io
	int tc;
	ii a, b, f;

	cin >> tc;
	while (tc--) {
		cin >> a.x >> a.y >> b.x >> b.y >> f.x >> f.y;
		if (a > b) swap(a, b);
		int ans = distance(a.x, a.y, b.x, b.y);
		if (a.x == b.x and a.x == f.x) {
			if (a.y < f.y and f.y < b.y)
				ans += 2;
			cout << ans << "\n";
			continue;
		}
		if (a.y == b.y and a.y == f.y) {
			if (a.x < f.x and f.x < b.x)
				ans += 2;
			cout << ans << "\n";
			continue;
		}
		cout << ans << "\n";
	}
	return 0;
}
