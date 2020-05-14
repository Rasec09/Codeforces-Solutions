#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

ll gcd(ll a, ll b) {
    return (b == 0 ? a : gcd(b, a % b));
}

int main() {
    optimizar_io
    int n; 
    ll a[100010], suf_gcd[100010];

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    suf_gcd[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suf_gcd[i] = gcd(a[i], suf_gcd[i + 1]);
    ll ans = a[0] * suf_gcd[1] / gcd(a[0], suf_gcd[1]);
    for (int i = 1; i + 1 < n; i++) {
        ll tmp = a[i] * suf_gcd[i + 1] / gcd(a[i], suf_gcd[i + 1]);
        ans = gcd(ans, tmp);
    }
    cout << ans << "\n";
    return 0;
}
