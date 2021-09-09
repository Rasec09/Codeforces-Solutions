#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc;
	string t;

	cin >> tc;
	while (tc--) {
		cin >> t;
		string seq;
		vector<int> cnt(26);
		for (int i = int(t.size()) - 1; i >= 0; i--) {
			if (cnt[t[i] - 'a'] == 0) {
				seq.push_back(t[i]);
			}
			cnt[t[i] - 'a']++;
		}
		reverse(seq.begin(), seq.end());
		bool possible = true;
		int size = 0;
		for (int i = 0; i < seq.size(); i++) {
			if (cnt[seq[i] - 'a'] % (i + 1) == 0) {
				size += cnt[seq[i] - 'a'] / (i + 1);
			}
			else {
				possible = false;
				break;
			}
		}
		if (!possible) {
			cout << "-1\n";
			continue;
		}
		string s = t.substr(0, size);
		string tmp = s;
		for (int i = 0; i < seq.size(); i++) {
			tmp.erase(remove(tmp.begin(), tmp.end(), seq[i]), tmp.end());
			s += tmp;
		}
		if (s == t)
			cout << t.substr(0, size) << " " << seq << "\n";
		else
			cout << "-1\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
