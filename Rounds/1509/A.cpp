#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

bool isInteger(int a, int b) {
	int x = (a + b) / 2;
	int y = (a + b + 1) / 2;
	return x == y;
}

int main() {
	optimizar_io
    int tc, n, a[2010];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		vector<int> ans(n), used(n);
		ans[0] = a[0];
		used[0] = 1;
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < n; j++) {
				if (isInteger(ans[i - 1], a[j]) and !used[j]) {
					ans[i] = a[j];
					used[j] = 1;
					break;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (ans[i] == 0) {
				for (int j = 0; j < n; j++) {
					if (!used[j]) {
						ans[i] = a[j];
						used[j] = 1;
						break;
					}
				}
			}
		}
		for (auto &x : ans) cout << x << " ";
		cout << "\n";
	}
	return 0;
}
