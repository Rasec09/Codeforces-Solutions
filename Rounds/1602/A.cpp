#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
 
int main() {
	optimizar_io
	int tc;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> s;
		int mn = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] < s[mn])
				mn = i;
		}
		cout << s[mn] << " ";
		for (int i = 0; i < s.size(); i++) {
			if (i == mn) continue;
			cout << s[i];
		}
		cout << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
