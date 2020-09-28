#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int n, a[100010];

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	priority_queue<int> pqMax;
	priority_queue<int,vector<int>,greater<int>> pqMin;
	for (int i = 0; i < n; i++) {
		pqMax.push(a[i]);
		pqMin.push(a[i]);
	}
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		if (i & 1) {
			ans[i] = pqMin.top();
			pqMin.pop();
		}
		else {
			ans[i] = pqMax.top();
			pqMax.pop();
		}
	}
	int cnt = 0;
	for (int i = 1; i + 1 < n; i++) {
		if (ans[i] < ans[i - 1] and ans[i] < ans[i + 1])
			cnt++;
	}
	cout << cnt << "\n";
	for (auto x : ans) {
		cout << x << " ";
	}
	cout << "\n";
	return 0;
}
