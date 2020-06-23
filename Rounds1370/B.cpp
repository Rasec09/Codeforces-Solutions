#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

vector<int> par, impar;

int main() {
	optimizar_io
	int tc, n, a[2010];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < 2 * n; i++) {
			cin >> a[i];
			if (a[i] & 1)
				impar.push_back(i);
			else
				par.push_back(i);
		}
		int idx = 0;
		vector<int> used(2 * n);
		for (int k = 0; k < n - 1; k++) {
			while (used[idx])
				idx++;
			if (a[idx] & 1) {
				used[idx] = 1;
				used[impar.back()] = 1;
				cout << idx + 1 << " " << impar.back() + 1 << "\n";
				impar.pop_back();
			}
			else {
				used[idx] = 1;
				used[par.back()] = 1;
				cout << idx + 1 << " " << par.back() + 1 << "\n";
				par.pop_back();
			}
		}
		par.clear();
		impar.clear();
	}
	return 0;
}
