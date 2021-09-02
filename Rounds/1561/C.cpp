#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
	
typedef vector<pair<int,int>> vii;

int main() {
	optimizar_io
	int tc, n, k, x;
	
	cin >> tc;
	while (tc--) {
		cin >> n;
		vector<vii> a(n, vii());
		for (int i = 0; i < n; i++) {
			cin >> k;
			for (int j = 0; j < k; j++) {
				cin >> x;
				a[i].emplace_back(x - j, x);
			}
		}
		sort(a.begin(), a.end(), [](vii &a, vii &b) {
			return *max_element(a.begin(), a.end()) < *max_element(b.begin(), b.end());
		});
		int low = 1, hig = 1e9+1; 
		while (low < hig) {
			int mid = low + (hig - low) / 2;
			auto check = [](vector<vii> &a, int x) -> bool {
				for (int i = 0; i < a.size(); i++) {
					for (int j = 0; j < a[i].size(); j++) {
						if (a[i][j].second >= x)
							return false;
						x++;
					}
				}
				return true;
			};
			if (check(a, mid))
				hig = mid;
			else
				low = mid + 1;
		}
		cout << low << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
