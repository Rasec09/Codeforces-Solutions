#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
    int tc, n, a[105], b[105], t[105];

	cin >> tc;
	while (tc--) {
		cin >> n;
		b[0] = 0;
		for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
		for (int i = 1; i <= n; i++) cin >> t[i];
		ll dep = 0, arr = 0; 
		for (int i = 1; i <= n; i++) {
			arr = dep + (a[i] - b[i - 1] + t[i]);
			dep = max(1LL * b[i], arr + (b[i] - a[i] + 1) / 2);
		}
		cout << arr << "\n";
	}
	return 0;
}
