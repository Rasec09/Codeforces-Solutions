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
		string ans;
		int prev = -1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '0') {
				if (prev == 1) {
					ans.push_back('0');
					prev = 0;
				}
				else {
					ans.push_back('1');
					prev = 1;
				}
			}
			else {
				if (prev == 2) {
					ans.push_back('0');
					prev = 1;
				}
				else {
					ans.push_back('1');
					prev = 2;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
