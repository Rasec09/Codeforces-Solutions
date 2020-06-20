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
		string ans;		
		ans.push_back(s[0]);
		ans.push_back(s[1]);
		for (int i = 2; i < s.size(); i++) {
			if (i & 1)
				ans.push_back(s[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}
