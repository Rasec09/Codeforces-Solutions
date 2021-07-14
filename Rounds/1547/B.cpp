#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

bool solve(string &s) {
	set<char> st;
	for (auto c : s) st.insert(c);
	if (st.size() != s.size()) return false;
	deque<char> dq;
	for (int i = 0; i < s.size(); i++) dq.push_back(s[i]);
	while (dq.size() > 1) {
		if (dq.front() > dq.back()) {
			char mx = dq.front();
			dq.pop_front();
			if (dq.back() + 1 != mx and dq.front() + 1 != mx)
				return false;
		}
		else if (dq.front() < dq.back()) {
			char mx = dq.back();
			dq.pop_back();
			if (dq.front() + 1 != mx and dq.back() + 1 != mx)
				return false;
		}
	}
	return (dq.front() == 'a' ? true : false);
}

int main() {
	optimizar_io
	int tc;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> s;
		cout << (solve(s) ? "YES" : "NO") << "\n";
	}
	return 0;
}
