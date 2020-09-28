#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

ll f(int a, int b, int x, int y, int n) {
	int diff = a - x;
	int mn = min(diff, n);
	a -= mn;
	n -= mn;
	diff = b - y;
	mn = min(diff, n);
	b -= mn;
	n -= mn;
	return 1LL * a * b;
}

int main() {
	optimizar_io
	int tc, a, b, x, y, n;

	cin >> tc;
	while (tc--) {
		cin >> a >> b >> x >> y >> n;
		cout << min(f(a, b, x, y, n), f(b, a, y, x, n)) << "\n";	
	}
	return 0;
}
