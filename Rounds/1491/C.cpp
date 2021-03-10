#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

struct FenwickTree {

	ll *ft;
	int size;

	FenwickTree(int n) : size(n) {
		ft = new ll[n + 1];
		for (int i = 0; i <= n; i++)
			ft[i] = 0;
	}

	void update(int idx, int val) {
		while (idx <= size) {
			ft[idx] += val;
			idx += (idx & -idx);
		}
	}

	ll query(int idx) {
		ll sum = 0;
		while (idx > 0) {
			sum += ft[idx];
			idx -= (idx & -idx);
		}
		return sum;
	}

	ll range(int i, int j) {
		return query(j) - query(i - 1);
	}
};

int main() {
	optimizar_io
    int tc, n, s[5010];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> s[i];
		FenwickTree ft(n + 1);
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			int times = ft.query(i);
			ans += max(0, s[i] - times - 1);
			int l = i + 2;
			int r = min(n, i + s[i]);
			ft.update(l, 1);
			ft.update(r + 1, -1);
			// Si ya se volvio 1 y aun seguimos saltando en el
			ft.update(i + 1, max(0, times - s[i] + 1));
			ft.update(i + 2, -1 * max(0, times - s[i] + 1));
		}
		cout << ans << "\n";
	}
	return 0;
}
