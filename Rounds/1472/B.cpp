#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, n, a[110];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		int uno = 0, dos = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] & 1)
				uno++;
			else
				dos++;
		}
		if (uno and dos) {
			if ((uno % 2 == 0) and (dos % 2 == 0))
				cout << "YES\n";
			else if ((uno % 2 == 0) and (dos % 2 == 1))
				cout << "YES\n";
			else 
				cout << "NO\n";
		}
		else {
			if (uno) {
				cout << (uno % 2 == 0 ? "YES\n" : "NO\n");
			}
			else {
				cout << (dos % 2 == 0 ? "YES\n" : "NO\n");
			}		
		}
	}
	return 0;
}
