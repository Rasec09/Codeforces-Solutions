#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int isPrime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return i;
	}
	return -1;
}

int main() {
	optimizar_io
	int tc, n;

	cin >> tc;
	while (tc--) {
		cin >> n;
		int d = isPrime(n);
		if (d == -1)
			cout << "1 " << n - 1 << "\n";
		else
			cout << n / d << " " << n - (n / d) << "\n";
	}
	return 0;
}
