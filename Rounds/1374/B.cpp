#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc;
	ll n;

	cin >> tc;
	while (tc--) {
		cin >> n;
		if (n == 1) {
			cout << "0\n";
			continue;
		}
		if (n % 2 != 0 and n % 3 != 0) {
			cout << "-1\n";
			continue;
		}
		int pot3 = 0;
		while (n % 3 == 0) {
			pot3++;
			n /= 3;
		}
		int pot2 = 0;
		while (n % 2 == 0) {
			pot2++;
			n /= 2;
		}
		if (pot2 > pot3) {
			cout << "-1\n";
		}
		else {
			if (n != 1) {
				cout << "-1\n";
			}
			else {
				int ans = pot3 + pot3 - pot2;
				cout << ans << "\n";
			}
		}
	}
	return 0;
}
