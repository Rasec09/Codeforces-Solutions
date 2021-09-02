#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
 
int main() {
	optimizar_io
	int tc, n;
	array<int,1000> a;

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		int ans = 0;
		for (int i = 0; !is_sorted(a.begin(), a.begin() + n); i++) {
			if (i & 1) {
				for (int j = 1; j + 1 < n; j += 2) {
					if (a[j] > a[j + 1])
						swap(a[j], a[j + 1]);
				}
			}
			else {
				for (int j = 0; j + 1 < n; j += 2) {
					if (a[j] > a[j + 1])
						swap(a[j], a[j + 1]);
				}
			}
			ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}
