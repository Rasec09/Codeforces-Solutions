#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, n, k;

	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		int size = 0;
		string ans;
		while (size < n) {
			for (int i = 0; i < k and size < n; i++) {
				ans.push_back('a');
				size++;
			}
			for (int i = 0; i < k and size < n; i++) {
				ans.push_back('b');
				size++;
			}
			for (int i = 0; i < k and size < n; i++) {
				ans.push_back('c');
				size++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
