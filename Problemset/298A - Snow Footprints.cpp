#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int n;
	string s;
	
	cin >> n >> s;
	int leftR = s.find_first_of('R');
	int rightR = s.find_last_of('R');
	char c = s[s.find_first_not_of('.')];
	int cntR = count(s.begin(), s.end(), 'R');
	if (cntR) {
		if (c == 'R') {
			int cntL = count(s.begin(), s.end(), 'L');
			if (cntL)
				cout << leftR + 1 << " " << rightR + 1 << "\n";
			else
				cout << leftR + 1 << " " << rightR + 2 << "\n";
		}
		else
			cout << rightR + 1 << " " << leftR + 1 << "\n";
	}
	else {
		int leftL = s.find_first_of('L');
		int rightL = s.find_last_of('L');
		cout << rightL + 1 << " " << leftL << "\n";
	}
	return 0;
}
