#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
    optimizar_io
    int tc, n, k;
    vector<int> c;

    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        c.assign(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
        set<int> colors;
        for (int i = 0; i < n; i++) {
            colors.insert(c[i]);
        }
        int ans = numeric_limits<int>::max();
        for (auto col : colors) {
            int cnt = 0;
            for (int i = 0; i < n; ) {
                if (c[i] != col) {
                    cnt++;
                    i += k;
                }
                else {
                    i++;
                }
            }
            ans = min(ans, cnt);
            // cout << col << " : " << cnt << "\n"; 
        }
        cout << ans << "\n";
    }
    return 0;
}
