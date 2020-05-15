#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;
const ll mod = 998244353;

int main() {
    optimizar_io
    int n;
    ll ans[200010];

    cin >> n;
    ans[0] = 10;
    ans[1] = 180;
    ll pot = 81;
    for (int i = 2; i < n; i++) {
        pot = (pot * 10) % mod;
        ans[i] = ((ans[i - 1] * 10) % mod) + (pot % mod);
        ans[i] %= mod;
    }
    for (int i = n - 1; i >= 0; i--)
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}
