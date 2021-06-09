#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, n;
	string s;
	vector<string> w;

	// 1-size substrings
	for (char c = 'a'; c <= 'z'; c++) {
		s.push_back(c);
		w.push_back(s);
		s.pop_back();
	}
	// 2-size subtrings
	for (char c = 'a'; c <= 'z'; c++) {
		s.push_back(c);
		for (char d = 'a'; d <= 'z'; d++) {
			s.push_back(d);
			w.push_back(s);
			s.pop_back();
		}
		s.pop_back();
	}
	// 3-size substrings
	for (char c = 'a'; c <= 'z'; c++) {
		s.push_back(c);
		for (char d = 'a'; d <= 'z'; d++) {
			s.push_back(d);
			for (char e = 'a'; e <= 'z'; e++) {
				s.push_back(e);
				w.push_back(s);
				s.pop_back();
			}
			s.pop_back();
		}
		s.pop_back();
	}
	cin >> tc;
	while (tc--) {
		cin >> n >> s;
		n = s.size();
		for (int i = 0; i < w.size(); i++) {
			if (s.find(w[i]) == -1) {
				cout << w[i] << "\n";
				break;
			}			
		}
	}
	return 0;
}
