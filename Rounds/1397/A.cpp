#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, n;
	string s[1010];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> s[i];
		vector<int> cnt(26);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < s[i].size(); j++)
				cnt[s[i][j] - 'a']++;
		}
		bool possible = true;
		for (int i = 0; i < cnt.size(); i++) {
			if (cnt[i] % n != 0) {
				possible = false;
				break;
			}
		}
		cout << (possible ? "YES\n" : "NO\n");
	}
	return 0;
}
