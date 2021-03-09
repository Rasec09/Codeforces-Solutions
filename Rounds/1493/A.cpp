#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
    int tc, n, k;

	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		vector<int> ans;
		for (int i = (k + 1) / 2; i < k; i++) {
			ans.push_back(i);
		}
		if (k < n) {
			for (int i = k + 1; i <= n; i++)
				ans.push_back(i);
		}
		cout << ans.size() << "\n";
		for (int a : ans) cout << a << " ";
		cout << "\n";
	}
	return 0;
}
