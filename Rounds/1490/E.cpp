#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

bool winner(int a[], int n, int x) {
	priority_queue<int,vector<int>,greater<int>> pq;
	int idx = -1, mx = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] <= x) {
			if (a[i] >= mx) {
				idx = i;
				mx = a[i];
			}
		}
	}
	if (idx == -1) return false;
	for (int i = 0; i < n; i++) {
		if (i == idx) continue;
		pq.push(a[i]);
	}
	ll tokens = a[idx];
	while (!pq.empty()) {
		if (tokens >= pq.top()) {
			tokens += pq.top();
			pq.pop();
		}
		else {
			return false;
		}
	}
	return true;
} 

int main() {
	optimizar_io
	int tc, n, a[200010];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		int l = 1, r = *max_element(a, a + n);
		while (l < r) {
			int mid = l + (r - l) / 2;
			if (winner(a, n, mid))
				r = mid;
			else
				l = mid + 1;
		}
		// cout << l << "\n";
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			if (a[i] >= l)
				ans.push_back(i + 1);
		}
		cout << ans.size() << "\n";
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << "\n";
	}
	return 0;
}
