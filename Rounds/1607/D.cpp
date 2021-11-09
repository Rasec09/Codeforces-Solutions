#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
 
int main() {
	optimizar_io
	int tc, n;
	array<int,200000> a;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		cin >> s;
		vector<int> red, blue;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'R')
				red.push_back(a[i]);
			else
				blue.push_back(a[i]);
		}
		sort(blue.begin(), blue.end());
		sort(red.begin(), red.end());
		vector<int> v;
		for (auto x : blue) v.push_back(x);
		for (auto y : red) v.push_back(y);
		int pos = blue.size();
		bool possible = true;
		for (int i = 0; i < n; i++) {
			if (i >= pos) { // lado rojo
				if (v[i] > i + 1) {
					possible = false;
					break;
				}
			}
			else { // lado azul
				if (v[i] < i + 1) {
					possible = false;
					break;
				}
			}
		}
		cout << (possible ? "YES" : "NO") << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
