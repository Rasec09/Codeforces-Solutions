#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> s;
		int turn = 0;
		bool finish = false;
		while (s.size()) {
			bool possible = false;
			for (int i = 0; i + 1 < s.size(); i++) {
				if (s[i] != s[i + 1]) {
					s.erase(i, 2);
					possible = true;
					break;
				}
			}
			if (!possible) {
				cout << (turn ? "DA\n" : "NET\n");
				finish = true;
				break;
			}
			turn = 1 - turn;
		}
		if (!finish)
			cout << (turn ? "DA\n" : "NET\n");
	}
	return 0;
}
