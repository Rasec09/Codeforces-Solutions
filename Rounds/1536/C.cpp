#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int gcd(int a, int b) {
	return (b == 0 ? a : gcd(b, a % b));
}

int main() {
	optimizar_io
	int tc, n;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> n >> s;
		n = s.size();
		map<pair<int,int>,int> cnt;
		cnt[make_pair(0,0)] = 1;
		vector<int> ans;
		int d = 0, k = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'D') 
				d++;
			else 
				k++;
			int g = gcd(d, k);
			pair<int,int> ii = make_pair(d / g, k / g);
			cnt[ii]++;
			ans.push_back(cnt[ii]);
		}
		for (auto a : ans) cout << a << " ";
		cout << "\n";
	}
	return 0;
}
