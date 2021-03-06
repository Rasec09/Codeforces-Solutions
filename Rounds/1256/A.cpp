#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
    int tc, a, b, n, S;

	cin >> tc;
	while (tc--) {
		cin >> a >> b >> n >> S;
		int d = S / n;
		S -= min(d, a) * n;
		if (b >= S)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
