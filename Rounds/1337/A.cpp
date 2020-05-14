#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int solve(int a, int b, int c, int d) {
    int x = b, y = c;
    for (int z = c; z <= d; z++) {
        if (x + y > z and x + z > y and y + z > x) {
            cout << x << " " << y << " " << z << "\n";
            return 0;
        }
    }
}

int main() {
    optimizar_io 
    int tc, a, b, c, d;

    cin >> tc;
    while (tc--) {
        cin >> a >> b >> c >> d;
        solve(a, b, c, d);
    }
    return 0;
}
