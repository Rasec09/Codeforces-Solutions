#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
 
int main() {
	optimizar_io
	int tc, a, b, c;

	cin >> tc;
	while (tc--) {
		cin >> a >> b >> c;
		if (a > b) swap(a, b);
		int dif = b - a;
		int size = dif * 2;
		if (a > size or b > size or c > size)
			cout << "-1\n";
		else {
			a--; b--; c--;
			int ans = (c + dif) % size;
			cout << ++ans << "\n";
		}
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
