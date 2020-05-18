#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

ll dig(ll n) {
	ll maxD = -1, minD = 10;
	while (n) {
		ll d = n % 10;
		maxD = max(maxD, d);
		minD = min(minD, d);
		n /= 10;
	}
	return maxD*minD;
}

int main() {
    optimizar_io
	int tc;
	ll n, k;

	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		for (int i = 1; i < k; i++) {
			ll tmp = dig(n);
			if (tmp == 0)
				break;
			n = n + tmp;
		}
		cout << n << "\n";
	}
    return 0;
}
