#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
    int tc, n, a[30010];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<int> cnt(3);
		for (int i = 0; i < n; i++) {
			cnt[a[i] % 3]++;
		}
		int ans = 0;
		for (int i = 0; i < 3; i++) {
			while (cnt[i] > n / 3) {
				if (i == 0) {
					if (cnt[1] < n / 3) {
						ans += 1;
						cnt[i]--;
						cnt[1]++;
					}
					else if (cnt[2] < n / 2) {
						ans += 2;
						cnt[i]--;
						cnt[2]++;
					}
				}
				else if (i == 1) {
					if (cnt[0] < n / 3) {
						ans += 2;
						cnt[i]--;
						cnt[0]++;
					}
					else if (cnt[2] < n / 2) {
						ans += 1;
						cnt[i]--;
						cnt[2]++;
					}
				}
				else {
					if (cnt[1] < n / 3) {
						ans += 2;
						cnt[i]--;
						cnt[1]++;
					}
					else if (cnt[0] < n / 2) {
						ans += 1;
						cnt[i]--;
						cnt[0]++;
					}
				}		
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
