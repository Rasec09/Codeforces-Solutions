#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int numZeros(int idx) {
	cout << "? 1 " << idx << endl;
	int sum = 0;
	cin >> sum;
	return idx - sum;
}

int main() {
	optimizar_io
	int n, t, k;

	cin >> n >> t >> k;
	int l = 1, r = n;
	while (l < r) {
		int m = (l + r) / 2;
		if (numZeros(m) >= k)
			r = m;
		else
			l = m + 1;
	}
	cout << "! " << l << "\n";
	return 0;
}
