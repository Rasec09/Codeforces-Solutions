#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
    optimizar_io
	int n, s;

	cin >> n >> s;
	if (s >= 2 * n) {
		cout << "YES\n";
		int d = s / n, sum = 0;
		for (int i = 0; i + 1 < n; i++) {
			cout << d << " ";
			sum += d;
		}
		cout << s - sum << "\n";
		cout << "1\n";
	}
	else {
		cout << "NO\n";
	}
    return 0;
}
