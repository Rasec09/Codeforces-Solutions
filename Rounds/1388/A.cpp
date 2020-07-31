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

int n;
bool possible;

void search(vi &nearPrime, int num, int firstNum, int secondNum, int level) {
	if (num <= 0) return;
	if (possible) return;
	if (level == 3) {
		int thirdNum = n - (num + nearPrime[firstNum] + nearPrime[secondNum]);
		if (nearPrime[firstNum] != num and nearPrime[secondNum] != num and thirdNum != num) {
			possible = true;
			cout << "YES\n" << nearPrime[firstNum] << " " << nearPrime[secondNum] << " " << thirdNum << " " << num << "\n";
			return;
		}
	}
	else {
		for (int i = 0; i < nearPrime.size(); i++) {
			if (i != firstNum and i != secondNum) {
				if (level == 0)
					search(nearPrime, num - nearPrime[i], i, -1, level + 1);
				if (level == 1)
					search(nearPrime, num - nearPrime[i], firstNum, i, level + 1);
				if (level == 2)
					search(nearPrime, num - nearPrime[i], firstNum, secondNum, level + 1);
			}
		}
	}
}

int main() {
	optimizar_io
	vi nearPrime;
	int tc;

	sieve(200000);
	for (int i = 0; i < primes.size(); i++) {
		for (int j = i + 1; j < primes.size(); j++) {
			ll pro = primes[i] * primes[j];
			if (pro > 2e5) break;
			nearPrime.push_back(pro);
		}
	}
	cin >> tc;
	while (tc--) {
		possible = false;
		cin >> n;
		search(nearPrime, n, -1, -1, 0);
		if (!possible) cout << "NO\n";
	}
	return 0;
}
