#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

struct tupla {
	int l, r, d;
};

int main() {
	optimizar_io
	int tc, n;
	array<int,50> a;

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<pair<int,int>> vii;
		for (int i = 0; i < n; i++) vii.emplace_back(a[i], i);
		sort(vii.begin(), vii.end());
		vector<tupla> ans;
		for (int i = 0; i + 1 < n; i++) {
			int d = i;
			for (int j = i; j < n; j++) {
				if (a[j] == vii[i].first){
					d = j;
					break;
				}
			}
			vector<int> tmp;
			for (int j = d; j < n; j++) {
				tmp.push_back(a[j]);
			}
			for (int j = i; j < d; j++) {
				tmp.push_back(a[j]);
			}
			for (int j = 0; j < tmp.size(); j++) {
				a[i + j] = tmp[j];
			}
			if (d - i > 0)
				ans.push_back({i + 1, n, d - i});
		}
		cout << ans.size() << "\n";
		for (int i = 0; i < ans.size(); i++) cout << ans[i].l << " " << ans[i].r << " " << ans[i].d << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
