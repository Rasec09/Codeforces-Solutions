#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;

vector<ll> buildAnswer(vector<ll> &a) {
	vector<ll> b = a;
	reverse(b.begin(), b.end());
	for (int i = 0; i < int(b.size()) / 2; i++) {
		b[i] *= -1;	
	}
	return b;
}

int main() {
	optimizar_io
	int tc, n;

	cin >> tc;
	while (tc--) {
		cin >> n;
		vector<ll> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		if (n & 1) {
			ll total = 0;
			for (int i = 1; i < 3; i++)
				total += llabs(a[0] * a[i]);
			total /= llabs(a[0]);
			vector<ll> ans;
			if (a[0] > 0) total *= -1;
			ans.push_back(total);
			for (int i = 1; i < 3; i++) {
				ll x = llabs(a[0]);
				if (a[i] < 0) x *= -1;
				ans.push_back(x);
			}
			vector<ll> tmp(a.begin() + 3, a.end());
			tmp = buildAnswer(tmp);
			for (auto v : ans) cout << v << " ";
			for (auto v : tmp) cout << v << " ";
		}
		else {
			vector<ll> ans = buildAnswer(a); 	
			for (auto v : ans) cout << v << " ";
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
