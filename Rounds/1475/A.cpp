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
		if (n & 1) {
			cout << "YES\n";
		}
		else {
			while (!(n & 1)) {
				n >>= 1;
			}
			if (n == 1)
				cout << "NO\n";
			else
				cout << "YES\n";
		}
	}
	return 0;
}
