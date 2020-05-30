#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

double promedio(ll n, ll h, ll c) {
    ll p = ((n + 1) / 2) * h + (n / 2) * c;
    double _p = p / (double) n;
    return _p; 
}

int main() {
    optimizar_io
    int tc, h, c, t;

    cin >> tc;
    while (tc--) {
    	cin >> h >> c >> t;
        if (t == h) {
            cout << "1\n";
            continue;
        }
        if ((h + c) / 2 >= t) {
            cout << "2\n";
            continue;
        }
        int l = 1, r = 1e9 + 7;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (mid % 2 == 0) mid--;
            double p = promedio(mid, h, c);
            if (p <= t)
                r = mid;
            else
                l = mid + 2;
        }
        if (abs(t - promedio(l - 2, h, c)) <= abs(t - promedio(l, h, c)))
            cout << l - 2 << "\n";
        else
            cout << l << "\n";
    }
    return 0;
}
/*
3
438837 375205 410506
656428 610660 653269
678522 242875 500989
9
1
5
*/
