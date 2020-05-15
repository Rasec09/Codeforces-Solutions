#include <bits/stdc++.h>
using namespace std;

vector<int> findSimple(string &s) {
	vector<int> pos;
	int l = 0, r = s.size() - 1;
	while (true) {
		while (s[l] != '(' and l < s.size()) l++;
		while (s[r] != ')' and r >= 0) r--;
		if (l < r) {
			//cout << l << " " << r << "\n";
			pos.push_back(l);
			l++;
			pos.push_back(r);
			r--;
		}
		else {
			break;
		}
	}
	/*cout << pos.size() << "\n";
	for (int i = 0; i < pos.size(); i++) 
		cout << pos[i] << " ";
	cout << "\n";*/
	return pos;
}

int main() {
	
	string s;
	vector<vector<int>> ans;

	cin >> s;
	//if (s == "()") return cout << "0\n", 0;
	while (true) {
		vector<int> v = findSimple(s);
		if (v.empty()) break;
		/*if (v.size() == s.size()) {
			v.pop_back();
			v.pop_back();
			sort(v.begin(), v.end());
			ans.push_back(v);
			break;	
		}*/
		sort(v.begin(), v.end());
		string _s;
		for (int i = 0; i < s.size(); i++) {
			if (!binary_search(v.begin(), v.end(), i))
				_s.push_back(s[i]);
		}
		s = _s;
		ans.push_back(v);
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].size() << "\n";
		for (int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] + 1 << " ";
		cout << "\n";
	}
	return 0;
}
