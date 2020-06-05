#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
    optimizar_io
    int tc, x1, y1, x2, y2;
    
    cin >> tc;
    while (tc--) {
        cin >> x1 >> y1 >> x2 >> y2;
        ll x = x2 - x1;
        ll y = y2 - y1;
        cout << x * y + 1 << "\n";
    }
    return 0;
}
