#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, x1, y1, x2, y2;

	cin >> tc;
	while (tc--) {
		cin >> x1 >> y1 >> x2 >> y2;
		int d = abs(x1 - x2) + abs(y1 - y2);
		if (x1 != x2 and y1 != y2)
			d += 2;
		cout << d << "\n";
	}
	return 0;
}
