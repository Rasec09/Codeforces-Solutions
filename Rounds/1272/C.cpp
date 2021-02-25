#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int n, k;
	string s;
	vector<int> valid(26);
	map<int,queue<int>> idx; 

	cin >> n >> k >> s;
	for (int i = 0; i < k; i++) {
		char c;
		cin >> c;
		valid[c - 'a'] = 1;
	}
	for (int i = 0; i < n; i++) {
		if (!valid[s[i] - 'a'])
			idx[s[i] - 'a'].push(i);
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int pos = (1 << 30); 
		for (int j = 0; j < 26; j++) {
			if (!valid[j] and !idx[j].empty()) {
				while (idx[j].front() < i)
					idx[j].pop();
				pos = min(pos, idx[j].front());
			}
		}
		// cout << pos << "\n";
		if (pos != (1 << 30))
			ans += pos - i;
		else
			ans += n - i;
	}
	cout << ans << "\n";
	return 0;
}
