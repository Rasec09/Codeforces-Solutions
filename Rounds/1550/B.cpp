#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, n, a, b;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> n >> a >> b >> s;
		int ans = a * n;
		if (b > 0) {
			ans += b * n;
		}
		else {
			s.resize(unique(s.begin(), s.end()) - s.begin());
			int zeros = count(s.begin(), s.end(), '0');
			ans += min(zeros + 1, (int(s.size()) - zeros) + 1) * b;
		}
		cout << ans << "\n";
	}
	return 0;
}
