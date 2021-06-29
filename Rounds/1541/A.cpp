#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
int main() {
	optimizar_io
	int tc, n, a[105];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) a[i] = i + 1;
		for (int i = 0; i + 1 < n; i +=2 ) swap(a[i], a[i + 1]);
		if (a[n - 1] == n) swap(a[n - 1], a[n - 2]);
		for (int i = 0; i < n; i++) cout << a[i] << " ";
		cout << "\n";
	}
	return 0;
}
