#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
    int tc, n, a[105];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		int mn = *min_element(a, a + n);
		int ans = 0;
		for (int i = 0; i < n; i++)
			if (a[i] > mn)
				ans++;
		cout << ans << "\n";
	} 
	return 0;
}
