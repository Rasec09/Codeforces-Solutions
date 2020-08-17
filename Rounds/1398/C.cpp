#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, n;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> n >> s;
		map<int,ll> cnt;
		cnt[0] = 1;
		ll sum = 0, ans = 0;
		for (int i = 0; i < s.size(); i++) {
			sum += (s[i] - '0') - 1;
			if (cnt.count(sum))
				ans += cnt[sum];
			cnt[sum]++;
		}
		cout << ans << "\n";
	}
	return 0;
}
