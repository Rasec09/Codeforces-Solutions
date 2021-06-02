#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
	
struct operation {
	int type, i, j;
};

int main() {
	optimizar_io
	int tc, n, a[1010];
	
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<operation> ans;
		for (int i = 0; i < n; i += 2) {
			if (a[i] < a[i + 1]) {
				ans.push_back({1, i, i + 1});
				ans.push_back({2, i, i + 1});
				ans.push_back({2, i, i + 1});
				ans.push_back({1, i, i + 1});
				ans.push_back({2, i, i + 1});
				ans.push_back({2, i, i + 1});
			}
			else {
				ans.push_back({1, i, i + 1});
				ans.push_back({2, i, i + 1});
				ans.push_back({1, i, i + 1});
				ans.push_back({1, i, i + 1});
				ans.push_back({2, i, i + 1});
				ans.push_back({1, i, i + 1});
			}
		}
		cout << ans.size() << "\n";
		for (auto op : ans) 
			cout << op.type << " " << op.i + 1 << " " << op.j + 1 << "\n";
	}
	return 0;
}
