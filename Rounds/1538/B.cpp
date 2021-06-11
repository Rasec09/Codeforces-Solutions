#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, n, a[200010];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		int total = 0;
		for (int i = 0; i < n; i++)
			total += a[i];
		if (total % n != 0) {
			cout << "-1\n";
			continue;
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
			if (a[i] > total / n)
				ans++;
		cout << ans << "\n";
	}
	return 0;
}
