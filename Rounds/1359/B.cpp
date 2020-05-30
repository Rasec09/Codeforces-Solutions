#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
    optimizar_io
    int tc, n, m, x, y;
    string s[105];

    cin >> tc;
    while (tc--) {
    	cin >> n >> m >> x >> y;
        for (int i = 0; i < n; i++) cin >> s[i];
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; ) {
                if (j + 1 < m and s[i][j] == '.' and s[i][j + 1] == '.') {
                    if (y <= 2 * x) {
                        ans += y;
                        j += 2;
                    }
                    else {
                        ans += x;
                        j++;
                    }
                }
                else if (s[i][j] == '.') {
                    ans += x;
                    j++;
                }
                else {
                    j++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
