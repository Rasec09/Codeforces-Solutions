#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;
ll ans[500010];

int main() {
    optimizar_io
 	int tc, n;

 	ans[1] = 0;
 	ans[3] = 8;
 	for (int i = 5; i <= 500001; i += 2) {
 		ll tmp = 2 * i + 2 * (i - 2);
 		tmp *= (i / 2);
 		ans[i] = tmp + ans[i - 2];
 	}
 	cin >> tc;
 	while (tc--) {
 		cin >> n;
 		cout << ans[n] << "\n";
 	}
    return 0;
}
