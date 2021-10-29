#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
 
int main() {
	optimizar_io
	int tc; 
	ll a, b, c;

	cin >> tc;
	while (tc--) {
		cin >> a >> b >> c;
		cout << (a + 2LL * b + 3LL * c) % 2 << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
