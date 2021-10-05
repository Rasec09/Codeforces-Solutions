#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, n;
	array<int,200000> a;

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		priority_queue<pair<int,int>> pq;
		for (int i = 0; i < n; i++) {
			if (a[i])
				pq.push(make_pair(a[i], i + 1));
		}
		vector<pair<int,int>> ans;
		while (pq.size() > 1) {
			pair<int,int> ii1 = pq.top(); pq.pop();
			pair<int,int> ii2 = pq.top(); pq.pop();
			ans.emplace_back(ii1.second, ii2.second);
			ii1.first -= 1;
			if (ii1.first)	
				pq.push(ii1);
			ii2.first -= 1;
			if (ii2.first)
				pq.push(ii2);
		}
		cout << ans.size() << "\n";
		for (int i = 0; i < ans.size(); i++) cout << ans[i].first << " " << ans[i].second << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
