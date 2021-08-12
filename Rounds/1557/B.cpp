#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, n, k;
	array<int,100000> a;

	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<pair<int,int>> b;
		for (int i = 0; i < n; i++) {
			b.emplace_back(a[i], i);
		}
		sort(b.begin(), b.end());
		for (int i = 0; i < n; i++) a[b[i].second] = i;
		int cnt = 0;
		for (int i = 0; i < n; ) {
			int j = i;
			while (j < n and a[j] + 1 == a[j + 1]) j++;
			i = j + 1;
			cnt++;
		}
		if (cnt <= k)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
