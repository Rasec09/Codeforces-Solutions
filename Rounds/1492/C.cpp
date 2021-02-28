#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	string s, t;
	int n, m, left[200010], right[200010];

	cin >> n >> m >> s >> t;
	int j = 0;
	for (int i = 0; i < n and j < m; i++) {
		if (s[i] == t[j]) {
			left[j] = i;
			j++;
		}
	}
	j = m - 1;
	for (int i = n - 1; i >= 0 and j >= 0; i--) {
		if (s[i] == t[j]) {
			right[j] = i;
			j--;
		}
	}
	int ans = 0;
	for (int i = 0; i + 1 < m; i++)
		ans = max(ans, right[i + 1] - left[i]);
	cout << ans << "\n";
	return 0;
}
