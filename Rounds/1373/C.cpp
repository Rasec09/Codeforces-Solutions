#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int p[1000010];

int main() {
	optimizar_io
	int tc;
	string s;
	map<int,int> idx;

	cin >> tc;
	while (tc--) {
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			p[i] = s[i] == '+' ? 1 : -1;
			if (i)
				p[i] += p[i - 1];
			if (!idx.count(p[i]))
				idx[p[i]] = i + 1; 
		}
		ll res = 0;
		for (int i = 1; idx.count(-1 * i); i++) {
			res += idx[-1 * i];
		}
		res += s.size();
		cout << res << "\n";
		idx.clear();
	}
	return 0;
}
