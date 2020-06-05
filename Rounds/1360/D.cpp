#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
    optimizar_io
    int tc, n, k;

    cin >> tc;
    while (tc--) {
    	cin >> n >> k;
        vector<int> div;
        for (ll i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                div.push_back(i);
                div.push_back(n / i);
            }
        }
        int mx = 1;
        for (int i = 0; i < div.size(); i++) {
            if (div[i] <= k)
                mx = max(mx, div[i]);
        }
        cout << n / mx << "\n";
    }
    return 0;
}
