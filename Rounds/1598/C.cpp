#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;

ll TwoSum(vector<int> &a, int n, ll x) {
	ll ans = 0;
	map<int,ll> freq;
	for (int i = 0; i < n; i++) {
		ll need = x - a[i];
		if (freq.count(need))
			ans += freq[need];
		freq[a[i]]++;
	}
	return ans;
}

int main() {
	optimizar_io
	int tc; 
	ll n;

	cin >> tc;
	while (tc--) {
		cin >> n;
		vector<int> a(n);
		ll sum = 0;
		for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
		ll x = 2LL * sum;
		if (x % n != 0) {
			cout << "0\n";
			continue;
		}
		x /= n;
		cout << TwoSum(a, n, x) << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
