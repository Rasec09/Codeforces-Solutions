#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
    int tc, r, b, d;

	cin >> tc;
	while (tc--) {
		cin >> r >> b >> d;
		int bolsas = min(r, b);
		int diff = (max(r, b) + bolsas - 1) / bolsas;
		cout << (diff - 1 <= d ? "YES\n" : "NO\n");
	}
	return 0;
}
