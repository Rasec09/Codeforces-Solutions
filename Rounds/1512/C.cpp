#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

bool solve(string &s, int zeros, int ones) {
	int i = 0, j = int(s.size()) - 1;
	while (i < j) {
		if (s[i] != s[j]) {
			if (s[i] == '?' and s[j] != '?') {
				if (s[j] == '0') {
					if (zeros) {
						s[i] = '0';
						zeros--;
					}
					else {
						return false;
					}
				}
				else if (s[j] == '1') {
					if (ones) {
						s[i] = '1';
						ones--;
					}
					else {
						return false;
					}
				}
			}
			else if (s[i] != '?' and s[j] == '?') {
				if (s[i] == '0') {
					if (zeros) {
						s[j] = '0';
						zeros--;
					}
					else {
						return false;
					}
				}
				else if (s[i] == '1') {
					if (ones) {
						s[j] = '1';
						ones--;
					}
					else {
						return false;
					}
				}
			}
		}
		i++;
		j--;
	}
	i = 0, j = int(s.size()) - 1;
	while (i < j) {
		if (s[i] == s[j]) {
			if (s[i] == '?') {
				if (zeros >= ones) {
					if (zeros >= 2) {
						s[i] = '0';
						s[j] = '0';
						zeros -= 2;
					}
					else {
						return false;
					}
				}
				else {
					if (ones >= 2) {
						s[i] = '1';
						s[j] = '1';
						ones -= 2;
					}
					else {
						return false;
					}
				}
			}
		}
		i++;
		j--;
	}
	if (s.size() % 2 == 1) {
		if (s[i] == '?') {
			if (zeros) {
				s[i] = '0';
				zeros--;
				return (zeros == 0 and ones == 0);
			}
			else if (ones) {
				s[i] = '1';
				ones--;
				return (zeros == 0 and ones == 0);
			}
			else {
				return false;
			}
		}
		else {
			return (zeros == 0 and ones == 0);
		}
	}
	return (zeros == 0 and ones == 0);
}

bool isPalindrome(string &s) {
	int i = 0, j = int(s.size()) - 1;
	while (i <= j) {
		if (s[i] != s[j])
			return false;
		i++;
		j--;
	}
	return true;
}

int main() {
	optimizar_io
	int tc, zeros, ones;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> zeros >> ones >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '0')
				zeros--;
			else if (s[i] == '1')
				ones--;
		}
		if (zeros < 0 or ones < 0) {
			cout << "-1\n";
			continue;
		}
		if (solve(s, zeros, ones)) {
			if (isPalindrome(s))
				cout << s << "\n";
			else
				cout << "-1\n";
		}
		else {
			cout << "-1\n";
		}
	}
	return 0;
}
