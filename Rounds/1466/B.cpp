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
		sort(a, a + n);
		set<int> diff;
		for (int i = 0; i < n; i++) {
			if (diff.count(a[i]))
				diff.insert(a[i] + 1);
			else
				diff.insert(a[i]);
		}
		cout << diff.size() << "\n";
	}
	return 0;
}
