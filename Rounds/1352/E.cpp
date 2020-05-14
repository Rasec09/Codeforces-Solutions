#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
    optimizar_io
 	int tc, n, a[8010];

 	cin >> tc;
 	while (tc--) {
 		cin >> n;
 		for (int i = 0; i < n; i++) cin >> a[i];
 		vector<int> special(n + 1);
 		for (int i = 0; i < n; i++) {
 			int sum = a[i];
 			for (int j = i + 1; j < n; j++) {
 				sum += a[j];
 				if (sum <= n)
 					special[sum] = 1;
 			}
 		}
 		int ans = 0;
 		for (int i = 0; i < n; i++) {
 			if (special[a[i]] == 1)
 				ans++;
 		}
 		cout << ans << "\n";
 	}
    return 0;
}
