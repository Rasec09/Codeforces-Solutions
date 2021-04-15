#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;
typedef vector<int> vi;

bitset<10000200> bs;
vi primesBySize[10];

int numSize(int x) {
	int size = 0;
	while (x) {
		size++;
		x /= 10;
	}
	return size;
}

void sieve(ll upperbound) {
	ll sieveSize = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= sieveSize; i++) {
		if (bs[i]) {
			for (ll j = i * i; j <= sieveSize; j += i)
				bs[j] = 0;
			primesBySize[numSize(i)].push_back(i);
		}
	}
}

ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}

int main() {
	optimizar_io
	int tc, a, b, c;

	primesBySize[9].push_back(100030001);
	primesBySize[9].push_back(100050001);
	sieve(10000200);
	cin >> tc;
	while (tc--) {
		cin >> a >> b >> c;
		if (a == b and b == c) {
			cout << primesBySize[c][0] << " " << primesBySize[c][0] << "\n";
			continue;
		}
		ll x = primesBySize[a - c + 1][0] * primesBySize[c][0];
		ll y = primesBySize[b - c + 1][1] * primesBySize[c][0];
		cout << x << " " << y << "\n";
	}
	return 0;
}
