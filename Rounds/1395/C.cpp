#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
	
typedef long long int ll;
int n, m, a[210], b[210], memo[210][520];

int dp(int i, int val) {
	if (i == n) return val;
	if (memo[i][val] != -1) return memo[i][val];
	int ans = (1 << 30);
	for (int j = 0; j < m; j++) {
		ans = min(ans, dp(i + 1, val | (a[i] & b[j])));		
	}
	return memo[i][val] = ans;
}

int main() {
	optimizar_io
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int j = 0; j < m; j++) cin >> b[j];
	memset(memo, -1, sizeof(memo));
	cout << dp(0, 0) << "\n";
	return 0;
}
