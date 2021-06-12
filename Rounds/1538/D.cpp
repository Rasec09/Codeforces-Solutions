#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;
typedef pair<int,int> factor;
typedef vector<int> vi;

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

vector<factor> primeFactors(ll N) {
	vector<factor> factores;
	ll idx = 0, pf = primes[0];
	while (N != 1 && (pf * pf <= N)) {
		ll power = 0;
		while (N % pf == 0) {
			N /= pf;
			power++;
		}
		if (power) 
			factores.push_back(factor(pf, power));
		pf = primes[++idx];
	}
	if (N != 1) factores.push_back(factor(N, 1));
	return factores;
}

int main() {
	optimizar_io
	int tc, a, b, k;

	sieve(10000000);
	cin >> tc;
	while (tc--) {
		cin >> a >> b >> k;
		if (k == 1) {
			if ((a % b == 0 or b % a == 0) and a != b)
				cout << "YES\n";
			else
				cout << "NO\n";
			continue;
		}
		int cnt = 0;
		vector<factor> factores = primeFactors(a);
		for (auto f : factores) cnt += f.second;
		factores = primeFactors(b);
		for (auto f : factores) cnt += f.second;
		cout << (cnt >= k ? "YES" : "NO") << "\n";
	}
	return 0;
}
/*
1
2 2 2
*/
