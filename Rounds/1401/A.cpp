#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, n, k;

	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		if (k >= n) {
			cout << k - n << "\n";
			continue;
		}
		int cnt = 0;
		if ((n + k) % 2 != 0) {
			n++;
			cnt++;
		}
		int b = (n + k) / 2; 
		while (b > n) {
			//cout << n << " " << b << "\n";
			n += 2;
			cnt += 2;
			b = (n + k) / 2;
		}
		cout << cnt << "\n";
	}
	return 0;
}
