#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, l, r;

	cin >> tc;
	while (tc--) {
        cin >> l >> r;
        int ans = 0;
        while (l or r) {
            ans += r - l;
            r /= 10; l /= 10;
        }
        cout << ans << '\n';
    }
	return 0;
}
