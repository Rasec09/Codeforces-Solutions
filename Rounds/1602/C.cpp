#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
 
int main() {
	optimizar_io
	int tc, n;
	array<int,200000> a;

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		map<int,int> cnt;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 30; j++) {
				if (a[i] & (1 << j))
					cnt[j]++;
			}
		}
		int g = -1;
		for (auto c : cnt) {
			if (g == -1)
				g = c.second;
			else
				g = __gcd(g, c.second);
		}
		if (g == -1) {
			for (int i = 0; i < n; i++) cout << i + 1 << " ";
			cout << "\n";
		}
		else {
			set<int> div;
			for (int i = 1; i * i <= g; i++) {
				if (g % i == 0) {
					div.insert(i);
					div.insert(g / i);
				}
			}
			for (auto x : div) cout << x << " ";
			cout << "\n";
		}
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
