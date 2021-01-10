#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int tc, n;
	string s = "989";

	int d = 0;
	while (s.size() < 200000) {
		s.push_back(d + '0');
		d++;
		d %= 10;
	}
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cout << s[i];
		}
		cout << "\n";
	}
	return 0;
}
