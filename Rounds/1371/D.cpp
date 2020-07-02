#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, n, k;
	vector<vector<int>> a;

	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		a.assign(n, vector<int>(n));
		int p = 0, q = 0, col = 0;
		for (int i = 0; i < k; i++){
			a[p][q] = 1;
			p++, q = (q + 1) % n;
			if (p == n) {
				p = 0;
				q = ++col;
			}
		}
		cout << (k % n ? "2\n" : "0\n");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << a[i][j];
			cout << "\n";
		}
	}
	return 0;
}
