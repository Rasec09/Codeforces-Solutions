#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int n, e[200010], memo[200010];

int dp(int i) {
	if (i == n) return 0;
	if (memo[i] != -1) return memo[i];
	if (i + e[i] > n)
		return memo[i] = dp(i + 1);
	return memo[i] = max(dp(i + e[i]) + 1, dp(i + 1)); 
}
 
int main() {
    optimizar_io
    int tc;

 	cin >> tc;
 	while (tc--) {
 		cin >> n;
 		for (int i = 0; i < n; i++) {
 			cin >> e[i];
 		}
 		sort(e, e + n, greater<int>());
 		fill(memo, memo + n, -1);
 		cout << dp(0) << "\n";
 	}
    return 0;
}
