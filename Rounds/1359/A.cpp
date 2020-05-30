#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
    optimizar_io
    int tc, n, m, k;

    cin >> tc;
    while (tc--) {
    	cin >> n >> m >> k;
        int jokers = min(m, n / k);
        m -= jokers;
        k--;
        m = ((m + k - 1) / k);
        cout << max(0, jokers - m) << "\n";
    }
    return 0;
}
