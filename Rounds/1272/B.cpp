#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
    int q;
	string s;

	cin >> q;
	while (q--) {
		cin >> s;
		map<char,int> freq;
		for (int i = 0; i < s.size(); i++)
			freq[s[i]]++;
		string ans;
		if (freq['U'] > 0 and freq['D'] > 0 and freq['L'] > 0 and freq['R']) {
			for (int i = 0; i < min(freq['L'], freq['R']); i++) {
				ans.push_back('R');
			}
			for (int i = 0; i < min(freq['U'], freq['D']); i++) {
				ans.push_back('U');
			}
			for (int i = 0; i < min(freq['L'], freq['R']); i++) {
				ans.push_back('L');
			}
			for (int i = 0; i < min(freq['U'], freq['D']); i++) {
				ans.push_back('D');
			}
		}
		else if (freq['L'] > 0 and freq['R'] > 0 and min(freq['U'], freq['D']) == 0) {
			ans.push_back('L');
			ans.push_back('R');
		}
		else if (freq['U'] > 0 and freq['D'] > 0 and min(freq['L'], freq['R']) == 0) {
			ans.push_back('U');
			ans.push_back('D');
		}
		cout << ans.size() << "\n";
		cout << ans << "\n";
	}
	return 0;
}
