#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, n, p[105];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> p[i];
		reverse(p, p + n);
		for (int i = 0; i < n; i++)
			cout << p[i] << " ";
		cout << "\n";
	}
	return 0;
}
