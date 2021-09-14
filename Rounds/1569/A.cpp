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
		n = s.size();
		bool found = false;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				int cntA = 0, cntB = 0;
				for (int k = i; k <= j; k++) {
					if (s[k] == 'a')
						cntA++;
					else
						cntB++;
				}
				if (cntA == cntB) {
					cout << i + 1 << " " << j + 1 << "\n";
					found = true;
					break;
				}
			}
			if (found) break;
		}
		if (!found)
			cout << "-1 -1\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
