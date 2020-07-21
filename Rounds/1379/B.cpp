#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;
ll l, r, m, a;

bool check(ll k, ll z, ll &d) {
    d = k * a + z;
    ll n = (m - d) / a;
    if (d < 0) {
        if (n > 0 and d + r >= l)
            return true;
    }
    else {
        if (n > 0 and d + l <= r)
            return true;
    }
    return false;
}

void solve() {
    cin >> l >> r >> m;
    for (a = l; a <= r; a++) {
        ll z = m % a, d;
        if (check(-1, z, d)) {
            if (d < 0)
                cout << a << " " << d + r << " " << r << "\n";
            else
                cout << a << " " << r << " " << r - d << "\n";
            return; 
        }
        if (check(0, z, d)) {
            if (d < 0)
                cout << a << " " << d + r << " " << r << "\n";
            else
                cout << a << " " << r << " " << r - d << "\n";
            return;
        }
    }
}

int main() {
    optimizar_io
    int tc;

    cin >> tc;
    while (tc--) 
        solve();
    return 0;
}
