#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

bool hasOddDiv(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			if (i & 1)
				return true;
			if ((n / i) & 1)
				return true;
		}
	}
	return false;
}

bool isPrime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int main() {
	optimizar_io
	int tc, n;

	cin >> tc;
	while (tc--) {
		cin >> n;
		if (n == 1) {
			cout << "FastestFinger\n";
		}
		else if (n == 2) {
			cout << "Ashishgup\n";
		}
		else {
			if (n & 1) {
				cout << "Ashishgup\n";
			}
			else {
				if (!hasOddDiv(n))
					cout << "FastestFinger\n";
				else {
					if (n % 4) {
						cout << (isPrime(n / 2) ? "FastestFinger\n" : "Ashishgup\n");
					}
					else {
						cout << "Ashishgup\n";
					}
				}
			}
		}
	}
	return 0;
}
