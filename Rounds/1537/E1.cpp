#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int n, k;
	string s, ans;

	cin >> n >> k >> s;
	n = s.size();
	string prefix;
	for (int i = 0; i < n; i++) {
		prefix.push_back(s[i]);
		string s1;
		while (s1.size() < k) s1 += prefix;
		while (s1.size() > k) s1.pop_back();
		ans = (i ? min(ans, s1) : s1);
	}
	while (ans.size() > k) ans.pop_back();
	cout << ans << "\n";
	return 0;
}
