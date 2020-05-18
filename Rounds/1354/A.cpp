#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
    optimizar_io
 	int tc;
 	ll a, b, c, d;

 	cin >> tc;
 	while (tc--) {
 		cin >> a >> b >> c >> d;
 		if (b >= a) {
 			cout << b << "\n";
 			continue;
 		}
 		ll minutes = 0;
 		minutes += b;
 		a -= b;
 		ll sleep = c - d;
 		if (sleep <= 0) {
 			cout << "-1\n";
 			continue;
 		}
 		ll need = (a + sleep - 1) / sleep;
 		minutes += c * need;
 		cout << minutes << "\n";
 	}
    return 0;
}
