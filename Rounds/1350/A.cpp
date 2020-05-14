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
    	int firstDiv = n;
    	for (int i = 2; i * i <= n; i++) {
    		if (n % i == 0) {
    			firstDiv = i;
    			break;
    		}
    	}
    	ll ans = (n + firstDiv) + 2 * (k - 1);  
    	cout << ans << "\n";
    }
    return 0;
}
