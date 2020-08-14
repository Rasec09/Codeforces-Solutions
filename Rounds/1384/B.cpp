#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

bool solve() {
	int n, k, l, d[300010], begin[300010], end[300010];
	
	cin >> n >> k >> l;
	vector<int> safe(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		safe[i] = (d[i] + k <= l);
		end[i] = l - d[i];
		begin[i] = -1 * end[i];
	}
	int t = begin[0];
	for (int i = 0; i < n; i++) {
		if (l - d[i] < 0) return false;
		if (t < begin[i] or t > end[i])
			return false;
		if (safe[i])
			t = begin[i + 1];
		else {
			if (t < begin[i + 1])
				t = begin[i + 1];
			else
				t++;
		}
	}
	return true;
}

int main() {
	optimizar_io
	int tc;

	cin >> tc;
	while (tc--) {
		cout << (solve() ? "Yes\n" : "No\n");
	}
	return 0;
}
