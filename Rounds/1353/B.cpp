#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
int main() {
    optimizar_io
 	int tc, n, k, a[35], b[35];

 	cin >> tc;
 	while (tc--) {
 		cin >> n >> k;
 		for (int i = 0; i < n; i++) cin >> a[i];
 		for (int i = 0; i < n; i++) cin >> b[i];
 		sort(a, a + n);
 		sort(b, b + n, greater<int>());
 		int ans = 0;
 		for (int i = 0; i < k; i++)
 			ans += max(a[i], b[i]);
 		for (int i = k; i < n; i++)
 			ans += a[i];
 		cout << ans << "\n";
 	}
    return 0;
}
