#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
    int tc, n, a[55];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] != 2)
				cnt++;
		}
		cout << cnt << "\n";
	}
	return 0;
}
