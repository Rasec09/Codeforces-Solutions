#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

bool solve(int a[], int n = 4) {
	int cnt = min({a[0], a[1], a[2]});
	int impar = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] & 1)
			impar++;
	}
	if (impar <= 1)
		return true;
	if (cnt >= 1) {
		impar = n - impar;
		if (impar <= 1) return true;
	}
	return false;
}

int main() {
	optimizar_io
	int tc, a[4];

	cin >> tc;
	while (tc--) {
		for (int i = 0; i < 4; i++) cin >> a[i];
		cout << (solve(a) ? "Yes\n" : "No\n");
	}
	return 0;
}
