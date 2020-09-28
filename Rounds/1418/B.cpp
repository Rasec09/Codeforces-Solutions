#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, n, a[110], l[110];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> l[i];
		priority_queue<int> pq;
		for (int i = 0; i < n; i++) {
			if (!l[i])
				pq.push(a[i]);
		}
		for (int i = 0; i < n; i++) {
			if (!l[i]) {
				a[i] = pq.top();
				pq.pop();
			}
		}
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << "\n";
	}
	return 0;
}
