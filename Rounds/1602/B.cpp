#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
 
int main() {
	optimizar_io
	int tc, n, q, pos, k;
	vector<int> a;

	cin >> tc;
	while (tc--) {
		cin >> n;
		a.assign(n, 0);
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<int> tmp = a;
		vector<vector<int>> b;
		b.push_back(a);
		while (true) {
			map<int,int> cnt;
			for (int i = 0; i < n; i++) cnt[tmp[i]]++;
			for (int i = 0; i < n; i++) tmp[i] = cnt[tmp[i]];
			if (tmp == b.back()) break;
			b.push_back(tmp);
		}
		cin >> q;
		while (q--) {
			cin >> pos >> k;
			if (k >= b.size())
				cout << b.back()[pos - 1] << "\n";
			else
				cout << b[k][pos - 1] << "\n";
		}
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
