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
		int turn = 1, score = 0;
		while (true) {
			int l = -1, r = -1, ones = 0;
			//cout << s << "\n";
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == '1') {
					int cnt = 1;
					for (int j = i; j < s.size(); j++) {
						//cout << s.substr(i, j-i+1) << "\n";
						if (s[j] == s[i]) {
							cnt++;
							if (cnt > ones) {
								l = i, r = j;
								ones = cnt;
							}								
						}
						else {
							break;
						}
					}
				}
			}
			//cout << l << " " << r << "\n";
			if (l == -1 and r == -1)
				break;
			if (turn) {
				score += (r - l + 1);
			}
			turn = 1 - turn;
			s.erase(l, r - l + 1);
		}
		cout << score << "\n";
	}
	return 0;
}
