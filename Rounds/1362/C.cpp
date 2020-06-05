#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
 
int main() {
    optimizar_io
    
    int tc;
    ll n;
 
    cin >> tc;
    while (tc--) {
        cin >> n;
        ll ans = 0, pot = 1;
        while (pot <= n) {
            ans += n / pot;
            pot <<= 1;
        }
        cout << ans << "\n";
    }
    return 0;
}
