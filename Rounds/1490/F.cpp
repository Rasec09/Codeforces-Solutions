#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, n, a[200010];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		map<int,int> freq;
		for (int i = 0; i < n; i++) freq[a[i]]++;
		vector<int> cnt;
		for (auto f : freq) {
			cnt.push_back(f.second);
		}
		sort(cnt.begin(), cnt.end());
		vector<int> acum(cnt.size());
		acum[0] = cnt[0];
		for (int i = 1; i < cnt.size(); i++) {
			acum[i] = cnt[i];
			acum[i] += acum[i - 1];
		}
		vector<int> C = cnt;
		auto it = unique(C.begin(), C.end());
		C.resize(it - C.begin());
		int ans = numeric_limits<int>::max();
		for (int i = 0; i < C.size(); i++) {
			int low = lower_bound(cnt.begin(), cnt.end(), C[i]) - cnt.begin();
			int hig = upper_bound(cnt.begin(), cnt.end(), C[i]) - cnt.begin();
			// cout << C[i] << " : " << low << " " << hig << "\n";
			int sum = 0;
			if (low != 0)
				sum += acum[low - 1];
			if (hig != cnt.size()) {
				int total = acum.back() - acum[hig - 1];
				sum += total - (acum.size() - hig) * C[i];
			}
			ans = min(ans, sum);
		}
		cout << ans << "\n";
	}
	return 0;
}
