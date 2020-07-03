#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, n;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> n >> s;
		int cnt = 0, mn = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(')
				cnt++;
			else
				cnt--;
			mn = min(mn, cnt);
		}
		cout << -1 * mn << "\n";
	}
	return 0;
}
