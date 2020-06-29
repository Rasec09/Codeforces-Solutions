#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc; 
	ll a, b, c;

	cin >> tc;
	while (tc--) {
		cin >> a >> b >> c;
		cout << (a < c ? "1 " : "-1 ");
		if (a * b <= c)
			cout << "-1\n";
		else
			cout << b << "\n";
	}
	return 0;
}
