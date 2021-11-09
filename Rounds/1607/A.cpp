#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
 
int main() {
	optimizar_io
	int tc;
	string order, s;

	cin >> tc;
	while (tc--) {
		cin >> order >> s;
		int ans = 0;
		for (int i = 0; i + 1 < s.size(); i++) {
			int pos1 = order.find(s[i]) + 1;
			int pos2 = order.find(s[i + 1]) + 1;
			ans += abs(pos1 - pos2);
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
