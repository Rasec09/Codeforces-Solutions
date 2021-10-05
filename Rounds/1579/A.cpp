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
		cin >> s;
		n = s.size();
		vector<int> cnt(3);
		for (int i = 0; i < n; i++) {
			cnt[s[i] - 'A']++;
		}				
		if (cnt[0] + cnt[2] == cnt[1])
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
