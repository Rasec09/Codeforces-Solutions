#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
 
ll powMod(ll a, ll n) {
	ll result = 1;
	while (n) {
		if (n & 1)
			result = (result * a);
		a = (a * a);
		n >>= 1;
	}
	return result;
}

int main() {
	optimizar_io
	int tc, n;
	array<int,60> a;

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		if (n == 1) {
			cout << (a[0] == 1 ? "1" : "0") << "\n";
			continue;
		}
		int cnt0 = 0, cnt1 = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == 0)
				cnt0++;
			else if (a[i] == 1)
				cnt1++;
		}
		if (cnt1) 
			cout << powMod(2, cnt0) * ll(cnt1) << "\n";
		else 
			cout << "0\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
