#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    optimizar_io
    int tc, n, m, r, c;

    cin >> tc;
    while (tc--) {
        cin >> n >> m >> r >> c;
        cout << max({
            dist(r, c, 1, 1),
            dist(r, c, n, 1),
            dist(r, c, 1, m),
            dist(r, c, n, m)	
        }) << "\n";
    }
    return 0;
}
