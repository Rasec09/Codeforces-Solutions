#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
ll sum;

ll f(ll i) {
	ll rem = sum - 2 * i;
	return abs(rem - i);
}

double ternary_search(double l, double r) {
    double eps = 1e-9;              //set the error limit here
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);      //evaluates the function at m1
        double f2 = f(m2);      //evaluates the function at m2
        if (f1 < f2)
            r = m2;
        else
            l = m1;
    }
    return f(l);	//return the maximum of f(x) in [l, r]
}

int main() {
	optimizar_io
	int tc; 
	ll a, b, c;

	cin >> tc;
	while (tc--) {
		cin >> a >> b >> c;
		sum = (a + b + c);
		/*ll ans = numeric_limits<ll>::max();
		for (ll i = 1; i < sum; i++) {
			ll rem = sum - 2 * i;
			// if (rem < i) break;
			cout << rem << " " << i << " " << abs(rem - i) <<"\n";
			ans = min(ans, abs(rem - i));
		}
		cout << ans << "\n";*/
		cout << ternary_search(1, (sum + 1) / 2) << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
