#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
int main() {
	optimizar_io
	int tc, a, b, n;
 
	cin >> tc;
	while (tc--) {
		cin >> a >> b >> n;
        if (a > b) swap(a, b);
        if (a > n or b > n) {
            cout << "0\n";
            continue;
        }
		int ans = 0;
		while (true) {
			a += b;
			ans++;
            if (a > n) break;
            b += a;
			ans++;
            if (b > n) break;
		}
        cout << ans << "\n";
	}
	return 0;
}
