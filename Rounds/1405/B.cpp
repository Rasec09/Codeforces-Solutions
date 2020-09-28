#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long int ll;

int main() {
	optimizar_io
	int tc, n;
	vector<int> a;

	cin >> tc;
	while (tc--) {
		cin >> n;
		a.assign(n, 0);
		for (int i = 0; i < n; i++) cin >> a[i];
		queue<int> q;
		for (int i = 0; i < n; i++)
			if (a[i] < 0)
				q.push(i);
		for (int i = 0; i < n; i++) {
			while (a[i] > 0) {
				while (!q.empty() and q.front() < i) q.pop();
				if (q.empty()) break;
				int op = min(a[i], -1 * a[q.front()]);
				a[i] -= op;
				a[q.front()] += op;
				if (a[q.front()] == 0) q.pop();
			}
			if (q.empty()) break;
		}
		ll cost = 0;
		for (int i = 0; i < n; i++) {
			//cout << a[i] << " ";
			if (a[i] > 0)
				cost += a[i];
		}
		cout << cost << "\n";
	}
	return 0;
}
