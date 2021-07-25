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
		map<char,int> letters;
		for (char c : s) letters[c]++;
		int cnt = 0;
		for (auto l : letters) {
			if (l.second >= 2)
				cnt += 2;
			else
				cnt++;
		}
		cout << cnt / 2 << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
