#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
 
int main() {
	optimizar_io
	int n, q, l, r;
	string s;

	cin >> n >> q >> s;
	vector<vector<int>> cnt;
	cnt.assign(26, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		cnt[s[i]- 'a'][i]++;
	}
	for (int i = 0; i < cnt.size(); i++) {
		for (int j = 1; j < cnt[i].size(); j++) {
			cnt[i][j] += cnt[i][j - 1];
		}
	}
	while (q--) {
		cin >> l >> r;
		l--; r--;
		int ans = 0;
		for (int i = 0; i < 26; i++) {
			int freq = cnt[i][r] - (l == 0 ? 0 : cnt[i][l - 1]);
			ans += (i + 1) * freq;
		}
		cout << ans << "\n";
	}
	return 0;
}
