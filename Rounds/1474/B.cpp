#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;
typedef vector<ll> vi;

bitset<10000010> bs;
vi primes;

void sieve(ll upperbound) {
	ll sieveSize = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= sieveSize; i++) {
		if (bs[i]) {
			for (ll j = i * i; j <= sieveSize; j += i)
				bs[j] = 0;
			primes.push_back(i);
		}
	}
}

int main() {
	optimizar_io
	int tc, d;

	sieve(10000000);
	cin >> tc;
	while (tc--) {
		cin >> d;
		int n1 = *lower_bound(primes.begin(), primes.end(), 1 + d);
		int n2 = *lower_bound(primes.begin(), primes.end(), n1 + d);
		cout << n1 * n2 << "\n";
	}
	return 0;
}
