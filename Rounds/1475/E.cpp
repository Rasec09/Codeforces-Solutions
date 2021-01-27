#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;
ll comb[1010][1010];
const ll mod = 1e9 + 7;
 
void precalcula() {
	comb[0][0] = 1LL;
	for (int i = 1; i <= 1000; i++) {
		for (int j = 0; j <= i; j++) {
			if (j)
				comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
			else
				comb[i][j] = 1LL;
		}
	}
}
 
ll combinatoria(int n, int k) {
	return (comb[n][k]) % mod;
}

int main() {
	optimizar_io
    int tc, n, k, a[1010];

	precalcula();
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		map<int,int> cnt1;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			cnt1[a[i]]++;
		}
		sort(a, a + n, greater<int>());
		map<int,int> cnt2;
		for (int i = 0; i < k; i++) cnt2[a[i]]++;
		ll ans = 1;
		for (auto freq : cnt2) {
			int n = cnt1[freq.first];
			int k = freq.second;
			// cout << n << " " << k << " " << combinatoria(n, k) << "\n";
			ans = (ans * combinatoria(n, k)) % mod;
		}
		cout << ans << "\n";
	}
	return 0;
}
