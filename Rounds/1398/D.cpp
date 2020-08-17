#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long int ll;

ll r[210], g[210], b[210], memo[210][210][210];

ll dp(int i, int j, int k) {
	if (memo[i][j][k] != -1) return memo[i][j][k];
	ll ans = 0;
	if (i > 0 and j > 0) 
		ans = max(ans, dp(i - 1, j - 1, k) + r[i] * g[j]);
	if (i > 0 and k > 0)
		ans = max(ans, dp(i - 1, j, k - 1) + r[i] * b[k]);
	if (j > 0 and k > 0)
		ans = max(ans, dp(i, j - 1, k - 1) + g[j] * b[k]);	
	return memo[i][j][k] = ans;
}

int main() {
	optimizar_io
	int red, green, blue;	
	cin >> red >> green >> blue;
	for (int i = 1; i <= red; i++) cin >> r[i];
	sort(r + 1, r + red + 1);
	for (int i = 1; i <= green; i++) cin >> g[i];
	sort(g + 1, g + green + 1);
	for (int i = 1; i <= blue; i++) cin >> b[i];
	sort(b + 1, b + blue + 1);
	memset(memo, -1, sizeof(memo));
	cout << dp(red, green, blue) << "\n";
	return 0;
}
