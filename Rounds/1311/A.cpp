#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
    int tc, a, b;

	cin >> tc;
	while (tc--) {
		cin >> a >> b;
		if (a < b) {
			int diff = b - a;
			if (diff & 1) {
				cout << "1\n";
			}
			else {
				cout << "2\n";	
			}
		}
		else if (a > b) {
			int diff = a - b;
			if (diff & 1) {
				cout << "2\n";
			}
			else {
				cout << "1\n";	
			}
		}
		else {
			cout << "0\n";
		}
	}
	return 0;
}
