#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, n, x;

	cin >> tc;
	while (tc--) {
		cin >> n >> x;
		if (n == 1 or n == 2) {
			cout << "1\n";
			continue;
		}
		int floor = 2;
		for (int i = 1; true; i++) {
			int low = ((i - 1) * x) + 3;
			int hig = (i * x) + 2;
			if (n >= low and n <= hig)
				break;
			floor++;
		}
		cout << floor << "\n";
	}
	return 0;
}
