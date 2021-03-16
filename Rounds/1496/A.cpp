#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

bool solve(string &s, int k) {
	int i = 0, j = int(s.size()) - 1;
	for (int cnt = 0; cnt < k; cnt++) {
		if (s[i] != s[j])
			return false;
		i++;
		j--;
	}
	return (i <= j);
}

int main() {
	optimizar_io
	int tc, n, k;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> n >> k >> s;
		if (k == 0) {
			cout << "YES\n";
		}
		else {
			cout << (solve(s, k) ? "YES\n" : "NO\n");
		}
	}
	return 0;
}
