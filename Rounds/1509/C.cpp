#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int a[2010];
ll memo[2010][2010];

ll dp(int l, int r) {
	if (l == r) return 0;
	if (memo[l][r] != -1) return memo[l][r];
	return memo[l][r] = min(dp(l + 1, r), dp(l, r - 1)) + (a[r] - a[l]);
}

int main() {
	optimizar_io
    int n;

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	memset(memo, -1, sizeof(memo));
	cout << dp(0, n - 1) << "\n";
	return 0;
}
