#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

bool solve(string &s) {
	int ones = -1, zeros = -1;
	for (int i = 0; i + 1 < s.size(); i++) {
		if (s[i] == '1' and s[i + 1] == '1') {
			ones = i;
			break;
		}
	}
	for (int i = int(s.size()) - 1; i > 0; i--) {
		if (s[i] == '0' and s[i - 1] == '0') {
			zeros = i;
			break;
		}
	}
	if (ones != -1 and zeros != -1 and ones < zeros) return false;
	return true;
}

int main() {
	optimizar_io
    int tc;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> s;
		if (s.size() <= 3)
			cout << "YES\n";
		else
			cout << (solve(s) ? "YES\n" : "NO\n");
	}
	return 0;
}
