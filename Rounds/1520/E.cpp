#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
    int tc, n;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> n >> s;
		vector<int> pos;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '*')
				pos.push_back(i);
		}
		n = pos.size();
		if (n == 0) {
			cout << "0\n";
			continue;
		}
		for (int i = 0; i < n; i++) {
			pos[i] -= i;
		}
		int m = pos[n / 2];
		ll ans = 0;
		for (int i = 0; i < n; i++)
			ans += abs(pos[i] - m);
		cout << ans << "\n";
	}
	return 0;
}
