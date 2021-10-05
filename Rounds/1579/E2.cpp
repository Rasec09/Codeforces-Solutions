#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;

typedef tree<int,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main() {
	optimizar_io
	int tc, n;
	array<int,200000> p;

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> p[i];
		ordered_set orderSet;
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			ll less = orderSet.order_of_key(p[i]);
			ll bigger = ll(orderSet.size()) - ll(orderSet.order_of_key(p[i] + 1));
			ans += min(less, bigger);
			orderSet.insert(p[i]);
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
