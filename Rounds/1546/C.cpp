#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

bool solve(vector<int> &a, int n) {
	map<int,pair<int,int>> ori, ord;
	for (int i = 0; i < n; i++) {
		if (i & 1)
			ori[a[i]].first++;
		else
			ori[a[i]].second++;
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
			if (i & 1)
				ord[a[i]].first++;
			else
				ord[a[i]].second++;
	}
	vector<int> b = a;
	b.resize(unique(b.begin(), b.end()) - b.begin());
	for (int i = 0; i < b.size(); i++) {
		if (ori[b[i]].first != ord[b[i]].first)
			return false;
		if (ori[b[i]].second != ord[b[i]].second)
			return false;
	}
	return true;
}
 
int main() {
	optimizar_io
	int tc, n;
	vector<int> a;

	cin >> tc;
	while (tc--) {
		cin >> n;
		a.assign(n, 0);
		for (int i = 0; i < n; i++) cin >> a[i];
		cout << (solve(a, n) ? "YES" : "NO") << "\n";
	}
	return 0;
}
