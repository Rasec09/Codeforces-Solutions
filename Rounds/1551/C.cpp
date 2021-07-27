#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int solveSomeChar(vector<string> &w, char c) {
	vector<int> s;
	for (int i = 0; i < w.size(); i++) {
		int freq = 0;
		for (char x : w[i]) {
			if (x == c)
				freq++;
		}
		s.emplace_back(freq - (int(w[i].size()) - freq));
	}
	sort(s.begin(), s.end(), greater<int>());
	int ans = 0, sum = 0;
	for (int i = 0; i < s.size(); i++) {
		if (sum + s[i] > 0) {
			ans++;
			sum += s[i];
		}
	}
	return ans;
}

int main() {
	optimizar_io
	int tc, n;
	vector<string> words;

	cin >> tc;
	while (tc--) {
		cin >> n;
		words.assign(n, "");
		for (int i = 0; i < n; i++) cin  >> words[i];
		int ans = 0;
		for (char c = 'a'; c <= 'z'; c++) {
			ans = max(ans, solveSomeChar(words, c));
		}
		cout << ans << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
