#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

bool isRegular(string &t) {
	vector<char> s;
	for (int i = 0; i < t.size(); i++) {
		if (t[i] == '(')
			s.push_back('(');
		else {
			if (s.empty())
				return false;
			else
				s.pop_back();
		}
	}
	return s.empty();
}

bool solve(string &s) {
	for (int mask = 0; mask < (1 << 3); mask++) {
		string t;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'A') {
				if (mask & (1 << 0))
					t.push_back('(');
				else
					t.push_back(')');
			}
			else if (s[i] == 'B') {
				if (mask & (1 << 1))
					t.push_back('(');
				else
					t.push_back(')');
			}
			else if (s[i] == 'C') {
				if (mask & (1 << 2))
					t.push_back('(');
				else
					t.push_back(')');
			}
		}
		if (isRegular(t))
			return true;
	}
	return false;
}

int main() {
	optimizar_io
    int tc;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> s;
		cout <<	(solve(s) ? "YES\n" : "NO\n");	
	}		
	return 0;
}
