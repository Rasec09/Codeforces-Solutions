#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int solve(string &a, string &b) {
	int ans = numeric_limits<int>::max();
	for (int i = 0; i < b.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			int size = j - i + 1;
			string c = b.substr(i, size);
			if (a.find(c) != -1)
				ans = min(ans, (int(a.size()) - size) + (int(b.size()) - size));
		}
	}
	if (ans == numeric_limits<int>::max())
		ans = a.size() + b.size();
	return ans;
}

int main() {
	optimizar_io
    int tc;
	string a, b;

	cin >> tc;
	while (tc--) {
		cin >> a >> b;
		if (a.size() < b.size()) swap(a, b);
		cout << solve(a, b) << "\n";		
	}
	return 0;
}
