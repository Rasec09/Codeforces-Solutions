#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, n, k;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> n >> k >> s;
		n = s.size();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '*') {
				s[i] = 'x';
				ans++;
				break;
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == '*') {
				s[i] = 'x';
				ans++;
				break;
			}
		}
		for (int i = 0; i + k <= n; i++) {
			if (s[i] == 'x') {
				bool exist = false;
				for (int j = i + 1; j <= i + k; j++) {
					if (s[j] == 'x') {
						exist = true;
						break;
					}
				}
				if (!exist) {
					for (int j = i + k; j > i; j--) {
						if (s[j] == '*') {
							s[j] = 'x';
							ans++;
							break;
						}
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
