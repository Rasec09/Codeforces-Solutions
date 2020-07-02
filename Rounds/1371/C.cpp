#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc; 
	ll v, c, n, m;

	cin >> tc;
	while (tc--) {
		cin >> v >> c >> n >> m;
		if (v < c) swap(v, c);
		if (v + c < n + m) {
			cout << "No\n";
			continue;
		}
		ll diff = v - c;
		if (diff >= n) {
			cout << (c >= m ? "Yes\n" : "No\n");
		}
		else {
			if (m > c) {
				cout << "No\n";
			}
			else {
				c -= m;
				if (v + c >= n)
					cout << "Yes\n";
				else
					cout << "No\n";
			}
		}
	}
	return 0;
}
