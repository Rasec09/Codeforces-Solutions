#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

bool isSorted(int a[], int n) {
	for (int i = 0; i + 1 < n; i++) {
		if (a[i] > a[i + 1])
			return false;
	}
	return true;
}

int main() {
	optimizar_io
	int tc, n, a[55];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		if (isSorted(a, n)) {
			cout << "0\n";
		}
		else {
			if (a[0] == 1 or a[n - 1] == n)
				cout << "1\n";
			else {
				if (a[0] == n and a[n - 1] == 1)
					cout << "3\n";
				else
					cout << "2\n";
			} 
		}
	}
	return 0;
}
