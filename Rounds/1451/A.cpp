#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

ll mulMod(ll a, ll b, ll m) {
	ll result = 0;
	while (b) {
		if (b & 1)
			result = (result + a) % m;
		a = (a + a) % m;
		b >>= 1;
	}
	return result;
}

ll powMod(ll a, ll n, ll m) {
	ll result = 1;
	while (n) {
		if (n & 1)
			result = mulMod(result, a, m);
		a = mulMod(a, a, m);
		n >>= 1;
	}
	return result;
}

bool isPrime(ll n) {
    if (n < 2) return false;
    if (n != 2 && n % 2 == 0) return false;
    
    ll d = n - 1;
    while (d % 2 == 0)
        d >>= 1;

    for (int i = 0; i < 15; i++) {
        ll a = rand() % (n - 1) + 1, tmp = d;
        ll x = powMod(a, d, n);
        while (tmp != n - 1 && x != 1 && x != n - 1) {
            x = mulMod(x, x, n);
            tmp <<= 1;
        }
        if (x != n - 1 && tmp % 2 == 0) {
            return false;
        }
    }
    return true;
}

int maxDiv(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return max(n / i, i);
		}
	}
}

int main() {
	optimizar_io
	int tc, n;

	cin >> tc;
	while (tc--) {
		cin >> n;
		if (n == 1) {
			cout << "0\n";
			continue;
		}
		if (n == 2) {
			cout << "1\n";
			continue;
		}
		if (isPrime(n)) {
			int root = sqrt(n - 1);
			cout << root + 1 << "\n";
		}
		else {
			int root = sqrt(n);
			cout << root << "\n";
		}
	}
	return 0;
}
