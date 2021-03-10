#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
    int n, q, t, k, a[100010];

	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> a[i];
	int cnt0 = 0, cnt1 = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] & 1)
			cnt1++;
		else
			cnt0++;
	}
	while (q--) {
		cin >> t >> k;
		if (t == 1) {
			if (a[k - 1] & 1) {
				cnt1--;
				cnt0++;
			}
			else {
				cnt0--;
				cnt1++;
			}
			a[k - 1] = 1 - a[k - 1];
		}
		else {
			if (k <= cnt1)
				cout << "1\n";
			else
				cout << "0\n";
		}
	}
	return 0;
}
