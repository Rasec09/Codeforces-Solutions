#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
 
ll sum(ll x) {
	ll res = x * (x + 1);
	return res + 1; 
}

int main() {
	optimizar_io
	int tc;
	ll k;

	cin >> tc;
	while (tc--) {
		cin >> k;
		ll low = 0, hig = 1e7;
		while (low < hig) {
			ll mid = low + (hig - low) / 2;
			if (k <= sum(mid))
				hig = mid;
			else
				low = mid + 1;
		}
		// cout << low << "\n";
		if (sum(low) == k) {
			cout << low + 1 << " " << low + 1 << "\n";
			continue;
		}
		if (sum(low) > k) low--;
		int r = low, c = low, len = low + 1;
		k -= sum(low);
		if (k < len) {
			c -= k;
		}
		else {
			c++;
			k -= len;
			r = k;
		}
		cout << r+1 << " " << c+1 << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
