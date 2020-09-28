#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;
typedef pair<int,int> ii;

int main() {
	optimizar_io
	int n, m, x, y;
	set<ii> visited;

	cin >> n >> m >> x >> y;
	visited.insert(ii(x, y));
	cout << x << " " << y << "\n";
	visited.insert(ii(1, y));
	cout << 1 << " " << y << "\n";
	visited.insert(ii(1, 1));
	cout << 1 << " " << 1 << "\n";
	for (int i = 0; i < n; i++) {
		if (i & 1) {
			for (int j = m - 1; j >= 0; j--) {
				if (visited.count(ii(i + 1, j + 1)))
					continue;
				cout << i + 1 << " " << j + 1 << "\n";
			}
		}
		else {
			for (int j = 0; j < m; j++) {
				if (visited.count(ii(i + 1, j + 1)))
					continue;
				cout << i + 1 << " " << j + 1 << "\n";
			}
		}
	}
	return 0;
}
