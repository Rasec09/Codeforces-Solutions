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
		if (n > k) {
			if (n % k == 0)
				cout << "1\n";
			else
				cout << "2\n";
		}
		else {
			cout << (k + n - 1) / n << "\n";
		}
	}
	return 0;
}
