#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
	
	int t, n, m, a[1010];

	cin >> t;
	while (t--) {
		cin >> n >> m;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		cout << min(sum, m) << "\n";	
	}
	return 0;
}
