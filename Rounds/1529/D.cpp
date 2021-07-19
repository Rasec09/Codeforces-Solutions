#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

const ll mod = 998244353;
array<ll,1000010> dp, divi;

void precalcula(int n) {
	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			divi[j] += 1;
		}
	}
}

int main() {
	optimizar_io
	int n;

	precalcula(1000000);
	cin >> n;
	dp[0] = dp[1] = 1;
	ll prefix = 2;
	for (int i = 2; i <= n; i++) {
		dp[i] = (prefix + divi[i]) % mod;
		prefix = (prefix + dp[i]) % mod;
	}
	cout << dp[n] << "\n";
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
