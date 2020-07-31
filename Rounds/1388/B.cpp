#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, n;

	cin >> tc;
	while (tc--) {
		cin >> n;
		string ans;
		ans.push_back('8');
		for (int i = 0; i < (n - 1) / 4; i++)
			ans.push_back('8');
		while (ans.size() != n)
			ans.push_back('9');
		reverse(ans.begin(), ans.end());
		cout << ans << "\n";
	}
	return 0;
}
