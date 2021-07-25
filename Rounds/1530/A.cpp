#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

string intToStr(int x) {
	stringstream ss;
	ss << x;
	string str = ss.str();
	return str;
}

int main() {
	optimizar_io
	int tc, n;

	cin >> tc;
	while (tc--) {
		cin >> n;
		string num = intToStr(n);
		int ans = 0;
		for (char c : num) {
			ans = max(ans, c - '0');
		}
		cout << ans << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?)
	* DON'T GET STUCK ON ONE APPROACH
*/
