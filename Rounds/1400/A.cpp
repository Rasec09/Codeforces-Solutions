#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, n;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> n >> s;
		string ans;
		for (int i = 0; i < n; i++) {
			for (int j = 0, k = 0; j < n; j++, k++) {
				if (k == i)
					ans.push_back(s[i + j]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
