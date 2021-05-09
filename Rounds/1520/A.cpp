#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, n;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> n >> s;
		n = s.size();
		set<char> task;
		bool ans = true;
		for (int i = 0, j = 0; i < n;) {
			if (task.count(s[i])) {
				ans = false;
				break;
			}
			task.insert(s[i]);
			while (s[i] == s[j])
				j++;
			i = j;
		}
		cout << (ans ? "YES\n" : "NO\n");
	}
	return 0;
}
