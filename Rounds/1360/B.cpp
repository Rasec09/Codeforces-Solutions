#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
    optimizar_io
    int tc, n, s[55];

    cin >> tc;
    while (tc--) {
    	cin >> n;
    	for (int i = 0; i < n; i++) cin >> s[i];
    	sort(s, s + n);
    	int ans = numeric_limits<int>::max();
    	for (int i = 0; i + 1 < n; i++) {
    		ans = min(ans, s[i + 1] - s[i]);
    	}
    	cout << ans << "\n";
    }
    return 0;
}
