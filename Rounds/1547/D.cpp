#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, n;
	array<uint32_t,200000> x;

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> x[i];
		vector<uint32_t> y = {0};
		uint32_t z = x[0];
		for (int i = 1; i < n; i++) {
			z |= x[i];
			y.push_back(x[i] ^ z);
		}
		for (auto a : y) cout << a << " ";
		cout << "\n";
	}
	return 0;
}
