#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int query(int l, int r) {
	int x;
	cout << "? " << l << " " << r << endl;
	cin >> x;
	return x;
}

int main() {
	optimizar_io
    int n;

	cin >> n;
	int l = 1, r = n;
	while (l + 1 < r) {
		int mid = (l + r) / 2;
		int smax = query(l, r);
		if (smax < mid) {
			int tmp = query(l, mid);
			if (smax == tmp)
				r = mid;
			else
				l = mid;
		}
		else {
			int tmp = query(mid, r);
			if (smax == tmp)
				l = mid;
			else
				r = mid;
		}
	}
	int mx = query(l, r);
	mx = (mx == l ? r : l);
	cout << "! " << mx << endl;
	return 0;
}
