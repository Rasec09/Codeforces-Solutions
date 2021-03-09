#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int n;

int query(int l, int r) {
	int x;
	cout << "? " << max(1, l) << " " << min(r, n) << endl;
	cin >> x;
	return x;
}

int main() {
	optimizar_io

	cin >> n;
	if (n == 2) {
		int mx = query(1, 2);
		mx = (mx == 1 ? 2 : 1);
		cout << "! " << mx << endl;
		return 0;
	}
	int smax = query(1, n);
	int l = 1, r = n - 1;
	while (l < r) {
		int mid = (l + r) / 2;
		// cout << "mid " << mid << "\n";
		int tmp = query(smax - mid, smax + mid);
		if (smax == tmp)
			r = mid;
		else
			l = mid + 1;
	}
	// cout << "(" << smax - l << "," << smax + l << ")\n";
	if (smax + l > n)
		cout << "! " << smax - l << endl;
	else if (smax - l < 1)
		cout << "! " << smax + l << endl;
	else {
		if (smax == query(smax, smax + l))
			cout << "! " << smax + l << endl;
		else
			cout << "! " << smax - l << endl;
	}
	return 0;
}
