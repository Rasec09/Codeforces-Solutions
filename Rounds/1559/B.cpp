#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int imperfect(string &s) {
	int n = s.size(), cnt = 0;
	for (int i = 0; i + 1 < n; i++) {
		if (s[i] == s[i + 1])
			cnt++;
	}
	return cnt;
}

int main() {
	optimizar_io
	int tc, n;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> n >> s;
		string s1 = s;
		string s2 = s;
		if (s[0] == '?') {
			s1[0] = 'B';
			for (int i = 1; i < n; i++) {
				if (s1[i] == '?') {
					s1[i] = (s1[i - 1] == 'B' ? 'R' : 'B');
				}
			}
			s2[0] = 'R';
			for (int i = 1; i < n; i++) {
				if (s2[i] == '?') {
					s2[i] = (s2[i - 1] == 'B' ? 'R' : 'B');
				}
			}
			if (imperfect(s1) < imperfect(s2))
				cout << s1 << "\n";
			else
				cout << s2 << "\n";
		}
		else {
			for (int i = 1; i < n; i++) {
				if (s[i] == '?') {
					s[i] = (s[i - 1] == 'B' ? 'R' : 'B');
				}
			}
			cout << s << "\n";
		}
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
