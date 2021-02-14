#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int count(int a, int b) {
	int cnt = 0;
	while (a) {
		a = a / b;
		cnt++;
	}
	return cnt;
}

int main() {
	optimizar_io
    int tc, a, b;

	cin >> tc;
	while (tc--) {
		cin >> a >> b;
		int cnt = 0;
		if (b == 1) cnt++, b++;
		if (b > a) {
			cout << ++cnt << "\n";
			continue;
		}
		int ans = numeric_limits<int>::max();
		for (int i = 0; b + i <= a and i < 1000000; i++) {
			ans = min(ans, cnt + count(a, b + i) + i);
			// cout << cnt + count(a, b + i) + i << "\n";
		}
		cout << ans << "\n";
	}
	return 0;
}
