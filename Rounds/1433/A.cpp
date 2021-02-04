#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int solve(int x) {
	int ans = 0;
	for (int i = 1; i <= 9; i++) {
		for (int j = i, size = 1; j < 10000; size++) {
			ans += size;
			if (j == x)
				return ans;		
			j *= 10;
			j += i;
		}
	}
}

int main() {
	optimizar_io
  int tc, x;

	cin >> tc;
	while (tc--) {
		cin >> x;		
		cout << solve(x) << "\n";
	}
	return 0;
}
