#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

bool solve(string &s, int m) {
	vector<int> mpos, tleft, tright;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'M')
			mpos.push_back(i);
	}
	for (int i = 0, k = 0; k < m; i++) {
		if (s[i] == 'T') {
			k++;
			tleft.push_back(i);
		}
	}
	for (int i = int(s.size()) - 1, k = 0; k < m; i--) {
		if (s[i] == 'T') {
			k++;
			tright.push_back(i);
		}
	}
	reverse(tright.begin(), tright.end());
	for (int i = 0; i < m; i++) {
		if (mpos[i] < tleft[i] or mpos[i] > tright[i])
			return false;
	}
	return true;
}

int main() {
	optimizar_io
    int tc, n;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> n >> s;
		n = s.size();
		int t = 0, m = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'T')
				t++;
			else
				m++;
		}
		if (2 * m != t) {
			cout << "NO\n";
			continue;
		}
		cout << (solve(s, m) ? "YES\n" : "NO\n");
	}
	return 0;
}
