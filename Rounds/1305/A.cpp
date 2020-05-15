#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t, n, a[105], b[105];

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << "\n";
		for (int i = 0; i < n; i++) cin >> b[i];
		sort(b, b + n);
		for (int i = 0; i < n; i++)
			cout << b[i] << " ";
		cout << "\n";
	}
	return 0;
}
