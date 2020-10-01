#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int n, a[200010], ans = 0;

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	map<ll,int> cnt;
	cnt[0] = 1;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (cnt.count(sum)) {
			ans++;
			sum = a[i];
			cnt.clear();
			cnt[0] = 1;
		}
		cnt[sum]++;
	}
	cout << ans << "\n";
	return 0;
}
