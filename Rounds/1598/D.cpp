#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
 
int main() {
	optimizar_io
	int tc; 
	ll n;
	array<int,200010> a, b;

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i];			
		}
		map<int,ll> cntT, cntD;
		for (int i = 0; i < n; i++) {
			cntT[a[i]]++;
			cntD[b[i]]++;
		}
		ll total = n * (n - 1) * (n - 2) / 6;
		for (int i = 0; i < n; i++) {
			total -= (cntT[a[i]] - 1) * (cntD[b[i]] - 1);
		}
		cout << total << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
