#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, n, k, a[1010];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		k = (n >> 1);
		int unos = 0, ceros = 0;
		for (int i = 0; i < n; i++) {
			if (a[i])
				unos++;
			else 
				ceros++;
		}
		if (n == 2) {
			if (unos == 1 and ceros == 1) {
				cout << 1 << "\n" << 0 << "\n";
			}
			else if (unos == 2 and ceros == 0) {
				cout << 2 << "\n" << "1 1\n";
			}
			else if (unos == 0 and ceros == 2) {
				cout << 2 << "\n" << "0 0\n";
			}
			continue;
		}
		vector<int> used(n, 1);
		if (unos > ceros) {
			for (int i = 0; i < n; i++) {
				if (k and a[i] == 0) {
					used[i] = 0;
					k--;
				}
			}
			for (int i = 0; i < n; i++) {
				if (unos % 2 == 0) break;
				if (k and a[i] == 1) {
					used[i] = 0;
					k--;
					unos--;
				}
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				if (k and a[i] == 1) {
					used[i] = 0;
					k--;
				}
			}
		}
		cout << count(used.begin(), used.end(), 1) << "\n";
		for (int i = 0; i < n; i++) {
			if (used[i] == 1)
				cout << a[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
