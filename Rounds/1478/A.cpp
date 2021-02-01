#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, n, a[105];

	cin >> tc;
	while (tc--) {
		cin >> n;
		map<int,int> freq;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			freq[a[i]]++;
		}
		int ans = numeric_limits<int>::min();
		for (auto f : freq)
			ans = max(ans, f.second);
		cout << ans << "\n";
	}
	return 0;
}
