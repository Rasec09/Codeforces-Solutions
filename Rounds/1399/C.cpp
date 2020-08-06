#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int cntPairs(int a[], int n, int k) {
	int cnt = 0;
	vector<int> used(n);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] + a[j] == k and !used[i] and !used[j]) {
				cnt++;
				used[i] = 1;
				used[j] = 1;
			}
		}
	}
	return cnt;
}

int main() {
	optimizar_io
	int tc, n, a[55];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		int ans = 0;
		for (int i = a[0] + a[1]; i <= a[n - 2] + a[n - 1]; i++) {
			//cout << i << " " << cntPairs(a, n, i) << "\n"; 
			ans = max(ans, cntPairs(a, n, i));
		}
		cout << ans << "\n";
	}
	return 0;
}
