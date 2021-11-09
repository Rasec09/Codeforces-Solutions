#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
 
int main() {
	optimizar_io
	int tc, n;
	array<int,200010> a;

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		priority_queue<ll,vector<ll>,greater<ll>> pq;
		for (int i = 0; i < n; i++)
			pq.push(a[i]);
		ll total = 0, ans = numeric_limits<ll>::min();
		while (!pq.empty()) {
			ll mn = pq.top();
			pq.pop();
			mn -= total;
			ans = max(ans, mn);
			total += mn;
		}		
		cout << ans << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
