#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
    optimizar_io 
    int tc, x, n, m;

    cin >> tc;
    while (tc--) {
        cin >> x >> n >> m;
        if (x > 10) {
            while (n-- and x > 10) {
                x >>= 1;
                x += 10;
            }
        }
        while (m--) {
            x -= 10;
        }
        cout << (x <= 0 ? "YES" : "NO") << "\n";
    }
    return 0;
}
