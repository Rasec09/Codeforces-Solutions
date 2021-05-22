#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
	
vector<int> solve(int n, int k) {
	vector<int> ans(n);
	vector<int> used(n + 1);
	for (int i = n, j = 0, pos = 1, l = 0; j < k; pos += 2, i--, j++) {
		ans[pos] = i;
		used[i] = 1;
		ans[pos - 1] = ++l;
		used[l] = 1;
	}
	for (int i = 0; i < n; i++) {
		if (!ans[i]) {
			for (int j = 1; j <= n; j++) {
				if (!used[j]) {
					ans[i] = j;
					used[j] = 1;
					break;
				}
			}
		}
	}
	return ans;
}
	
int main() {
	optimizar_io
	int tc, n, k;
	
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		
		if (n & 1) {
			if (k > n / 2) {
				cout << "-1\n";
			}
			else {
				vector<int> ans = solve(n, k);
				for (auto a : ans) cout << a << " ";
				cout << "\n";
			}
		}
		else {
			if (k >= n / 2) {
				cout << "-1\n";
			}
			else {
				vector<int> ans = solve(n, k);
				for (auto a : ans) cout << a << " ";
				cout << "\n";
			}
		}
	}
	return 0;
}
