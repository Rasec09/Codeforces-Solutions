#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
 
int main() {
	optimizar_io
	int tc, n, k;
	array<int,400000> a;

	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		map<int,int> ratones;
		for (int i = 0; i < k; i++) cin >> a[i], ratones[a[i]]++;
		int g = 0, ans = 0;
		while (!ratones.empty()) {
			int next = ratones.rbegin()->first;
			int diff = n - next;
			// Movimiento raton
			ans++;
			ratones[next]--;
			if (ratones[next] == 0)
				ratones.erase(next);
			// Movimiento gato
			g += diff;
			while (!ratones.empty() and ratones.begin()->first <= g) {
				ratones.erase(ratones.begin());
			}
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
