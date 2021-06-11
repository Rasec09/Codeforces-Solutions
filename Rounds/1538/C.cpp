#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
 
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

typedef long long int ll;

int main() {
	optimizar_io
	int tc, n, l, r, a[200010];

	cin >> tc;
	while (tc--) {
		cin >> n >> l >> r;
		for (int i = 0; i < n; i++) cin >> a[i];
		ordered_set os;
		os.insert(a[0]);
		ll ans = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] >= r) continue;
			int x = (l > a[i] ? l - a[i] : 1);
			int y = abs(r - a[i]);
			ll low = os.order_of_key(x);
			ll hig = os.order_of_key(y + 1);
			ans += (hig - low);
			os.insert(a[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}
