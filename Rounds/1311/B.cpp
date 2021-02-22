#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

bool exist(int p[], int n, int x) {
	for (int i = 0; i < n; i++) {
		if (p[i] == x)
			return true;
	}
	return false;
}

bool solve(int a[], int n, int p[], int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j + 1 < n; j++) {
			if (a[j] > a[j + 1]) {
				// cout << j << " " << j + 1 << "\n";
				if (exist(p, m, j))
					swap(a[j], a[j + 1]);
				else
					return false;
			}
		}
	}
	return true;
}

int main() {
	optimizar_io
	int tc, n, m, a[105], p[105];

	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++) {
			cin >> p[i];
			p[i]--;
		}
		cout << (solve(a, n, p, m) ? "YES\n": "NO\n");		
	}
	return 0;
}
