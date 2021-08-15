#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

bool possible(string &s, string &t) {
	if (s.size() < t.size()) return false;
	int i = int(s.size()) - 1, j = int(t.size()) - 1;
	while (i >= 0) {
		if (s[i] == t[j]) {
			i--; j--;
			if (j == -1)
				return true;
		}
		else {
			i -= 2;
		}
	}
	return false;
}

int main() {
	optimizar_io
	int q;
	string s, t;

	cin >> q;
	while (q--) {
		cin >> s >> t;
		cout << (possible(s, t) ? "YES" : "NO") << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
