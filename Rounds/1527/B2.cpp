#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

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
	int tc, n;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> n >> s;
		n = s.size();
		int zeros = count(s.begin(), s.end(), '0');
		if (isPalindrome(s)) {
			if (zeros == 0)
				cout << "DRAW\n";
			else if (zeros == 1 or !(zeros & 1))
				cout << "BOB\n";
			else
				cout << "ALICE\n";
		}
		else {
			if ((n & 1) and zeros == 2 and s[n >> 1] == '0')
				cout << "DRAW\n";
			else
				cout << "ALICE\n";
		}
	}
	return 0;
}
