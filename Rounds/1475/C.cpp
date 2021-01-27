#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
    int tc, n, m, k, a[200010], b[200010];

	cin >> tc;
	while (tc--) {
		cin >> n >> m >> k;
		for (int i = 0; i < k; i++) cin >> a[i];
		for (int i = 0; i < k; i++) cin >> b[i];
		ll totalPairs = (1LL * k * k) - k;
		map<int,int> cntA, cntB;
		for (int i = 0; i < k; i++) {
			cntA[a[i]]++;
			cntB[b[i]]++;
		}
		ll bad = 0;
		for (int i = 0; i < k; i++) {
			bad += (cntA[a[i]] - 1) + (cntB[b[i]] - 1);
		}
		ll ans = totalPairs - bad;
		ans >>= 1;
		cout << ans << "\n";
	}
	return 0;
}
