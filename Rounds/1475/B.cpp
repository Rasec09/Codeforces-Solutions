#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int memo[1000010];

bool dp(int sum) {
	if (sum == 0) return true;
	if (sum < 0) return false;
	if (memo[sum] != -1) return memo[sum];
	return memo[sum] = (dp(sum - 2020) | dp(sum - 2021));
}

int main() {
	optimizar_io
    	int tc, n;
	cin >> tc;
	memset(memo, -1, sizeof(memo));
	while (tc--) {
		cin >> n;
		cout << (dp(n) ? "YES\n" : "NO\n"); 
	}
	return 0;
}
