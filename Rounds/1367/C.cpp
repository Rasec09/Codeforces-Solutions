#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, n, k;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> n >> k >> s;
		vector<int> ones;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1') {
				ones.push_back(i);
			}
		}
		ones.push_back(1 << 30);
		int ans = 0;
		for (int i = 0; i < s.size(); ) {
			//cout << i << " ";
			if (s[i] == '1') {
				i += k + 1;
			}
			else {
				int pos = lower_bound(ones.begin(), ones.end(), i) - ones.begin();
				pos = ones[pos];
				if (pos >= i + k + 1) {
					ans++;
					i += k + 1;
				}
				else 
					i = pos;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
