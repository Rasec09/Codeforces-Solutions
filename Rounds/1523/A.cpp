#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
    int tc, n, m;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> n >> m >> s;
		n = s.size();
		for (int i = 0; i < m; i++) {
			vector<int> alive;
			for (int j = 0; j < n; j++) {
				if (s[j] == '0') {
					int neighbour = 0;
					if (j - 1 >= 0)
						neighbour += (s[j - 1] - '0');
					if (j + 1 < n)
						neighbour += (s[j + 1] - '0');
					if (neighbour == 1)
						alive.push_back(j);
				}
			}
			string prev = s;
			for (int j = 0; j < alive.size(); j++) {
				s[alive[j]] = '1';
			}
			if (prev == s)
				break;
		}
		cout << s << "\n";
	}
	return 0;
}
