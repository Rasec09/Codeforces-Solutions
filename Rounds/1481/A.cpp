#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, x, y;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> x >> y >> s;
		map<char,int> mp;
		for (int i = 0; i < s.size(); i++) {
			mp[s[i]]++;
		}
		if (x >= 0 and y >= 0) {
			if (mp['R'] >= x and mp['U'] >= y) 
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else if (x >= 0 and y <= 0) {
			if (mp['R'] >= x and mp['D'] >= -1 * y) 
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else if (x <= 0 and y >= 0) {
			if (mp['L'] >= -1 * x and mp['U'] >= y) 
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else if (x <= 0 and y <= 0) {
			if (mp['L'] >= -1 * x and mp['D'] >= -1 * y) 
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
	return 0;
}
