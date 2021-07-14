#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

bool solve(int k, queue<int> &a, queue<int> &b, vector<int> &ans) {
	vector<int> lines;
	for (int i = 0; i < k; i++) lines.push_back(i + 1);
	while (!a.empty() and !b.empty()) {
		if (a.front() == 0) {
			lines.push_back(int(lines.size()) + 1);
			ans.push_back(a.front());
			a.pop();
		}
		else if (b.front() == 0) {
			lines.push_back(int(lines.size()) + 1);
			ans.push_back(b.front());
			b.pop();
		}
		else {
			if (a.front() <= b.front()) {
				if (a.front() > lines.size())
					return false;
				else {
					ans.push_back(a.front());
					a.pop();
				}
			}
			else {
				if (b.front() > lines.size())
					return false;
				else {
					ans.push_back(b.front());
					b.pop();
				}
			}
		}
	}
	while (!a.empty()) {
		if (a.front() == 0) {
			lines.push_back(int(lines.size()) + 1);
			ans.push_back(a.front());
			a.pop();	
		}
		else {
			if (a.front() > lines.size())
				return false;
			else {
				ans.push_back(a.front());
				a.pop();
			}
		}
	}
	while (!b.empty()) {
		if (b.front() == 0) {
			lines.push_back(int(lines.size()) + 1);
			ans.push_back(b.front());
			b.pop();
		}
		else {
			if (b.front() > lines.size())
				return false;
			else {
				ans.push_back(b.front());
				b.pop();
			}
		}
	}
	return true;
}

int main() {
	optimizar_io
	int tc, n, m, k, x;
	queue<int> a, b;

	cin >> tc;
	while (tc--) {
		cin >> k >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> x;
			a.push(x);
		}
		for (int i = 0; i < m; i++) {
			cin >> x;
			b.push(x);
		}
		vector<int> ans;
		if (!solve(k, a, b, ans)) {
			cout << "-1\n";
		}
		else {
			for (auto x : ans) cout << x << " ";
			cout << "\n";
		}
		while (!a.empty()) a.pop();
		while (!b.empty()) b.pop();
	}
	return 0;
}
