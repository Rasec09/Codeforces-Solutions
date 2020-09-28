#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

string build(string w, int x) {
	string t;
	for (int i = 0; i < w.size(); i++) {
		if (i - x >= 0 and w[i - x] == '1') {
			t.push_back('1');
			continue;
		}
		if (i + x < w.size() and w[i + x] == '1') {
			t.push_back('1');
			continue;
		}
		t.push_back('0');
	}
	return t;
}

int main() {
	optimizar_io
	int tc, x, n;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> s >> x;
		n = s.size();
		string w(n, '1');
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				if (i - x >= 0) w[i - x] = '0';
				if (i + x < n) w[i + x] = '0';	
			}
		}
		string aux = build(w, x);
		if (aux == s)
			cout << w << "\n";
		else
			cout << "-1\n";
	}
	return 0;
}
