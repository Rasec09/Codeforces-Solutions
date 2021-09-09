#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

void addOne(string &s) {
	int num = stoi(s, nullptr, 10);
	num++;
	s = to_string(num);
}

string solve(string n, int k) {
	while (true) {
		set<char> s;
		for (auto c : n) s.insert(c);
		if (s.size() <= k) return n;

		s.clear();
		string p;
		for (int i = 0; i < n.size(); i++) {
			if (s.size() > k)
				break;
			p.push_back(n[i]);
			s.insert(n[i]);
		}
		addOne(p);
		for (int i = 0; i < n.size(); i++) {
			if (i < p.size())
				n[i] = p[i];
			else
				n[i] = '0';
		}
	}
}

int main() {
	optimizar_io
	int tc, k;
	string n;

	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		cout << solve(n, k) << "\n";
	}
	return 0;
}
