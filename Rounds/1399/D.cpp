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
		vector<int> EndWithOne, EndWithZero;
		vector<vector<int>> subseq;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				if (!EndWithOne.empty()) {
					subseq[EndWithOne.back()].emplace_back(i);
					EndWithZero.emplace_back(EndWithOne.back());
					EndWithOne.pop_back();
				}
				else {
					int idx = EndWithZero.size();
					vector<int> tmp;
					tmp.emplace_back(i);
					subseq.emplace_back(tmp);
					EndWithZero.emplace_back(idx);
				}
			}
			else {
				if (!EndWithZero.empty()) {
					subseq[EndWithZero.back()].emplace_back(i);
					EndWithOne.emplace_back(EndWithZero.back());
					EndWithZero.pop_back();
				}
				else {
					int idx = EndWithOne.size();
					vector<int> tmp;
					tmp.emplace_back(i);
					subseq.emplace_back(tmp);
					EndWithOne.emplace_back(idx);	
				}
			}
		}
		int color = 0;
		vector<int> ans(n);
		for (vector<int> x : subseq) {
			++color;
			for (int i = 0; i < x.size(); i++) {
				ans[x[i]] = color;
			}
		}
		cout << color << "\n";
		for (int x : ans)
			cout << x << " ";
		cout << "\n";
	}
	return 0;
}
