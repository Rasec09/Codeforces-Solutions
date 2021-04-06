#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

const ll mod = 1e9 + 7;
ll memo[1010][1010][2];
int n;

ll dp(int idx, int k, int flow) {
	if (k == 1) return 1LL;
	if (idx == 0 or idx == n + 1) return 1LL;
	if (memo[idx][k][flow] != -1) return memo[idx][k][flow]; 
	if (flow)
		return memo[idx][k][flow] = (dp(idx + 1, k, flow) + dp(idx - 1, k - 1, 1 - flow)) % mod;
	else
		return memo[idx][k][flow] = (dp(idx + 1, k - 1, 1 - flow) + dp(idx - 1, k, flow)) % mod;
}

int main() {
	optimizar_io
    int tc, k;

	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		if (n == 1) {
			cout << (k > 1 ? "2\n" : "1\n");
			continue;
		}
		memset(memo, -1, sizeof(memo));
		cout << dp(1, k, 1) << "\n";
	}
	return 0;
}
