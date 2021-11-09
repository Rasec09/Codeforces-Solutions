#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
 
int main() {
	optimizar_io
	int tc;
	ll pos, x;
  
	cin >> tc;
	while (tc--) {
		cin >> pos >> x;
		ll t = x / 4;
		ll mod = ((x % 4) + 4) % 4;
		if (mod == 0) {
			cout << 0 + pos << "\n";
		}
		else if (mod == 1) {
			cout << ((pos & 1 ? 1 : -1) * (4* t + 1)) + pos << "\n";
		}
		else if (mod == 2) {
			cout << ((pos & 1 ? -1 : 1) * 1) + pos << "\n";
		}
		else {
			cout << ((pos & 1 ? -1 : 1) * (4* t + 4)) + pos << "\n";
		}
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
