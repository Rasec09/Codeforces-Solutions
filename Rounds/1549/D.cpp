#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
#define MAXN 200010
#define LOGN 20

typedef long long int ll;

vector<ll> diff;
ll sparse[MAXN][LOGN];
int logs[MAXN];

ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}

void preprocess(int n) {
	
	int i, j;

	for (i = 2; i <= n; i++)
		logs[i] = logs[i >> 1] + 1;

	for (i = 0; i < n; i++)
		sparse[i][0] = diff[i];

	for (j = 1; (1 << j) <= n; j++) {
		for (i = 0; i + (1 << j) - 1 < n; i++) {
			ll x = sparse[i][j - 1];
			ll y = sparse[i + (1 << (j - 1))][j - 1];
			sparse[i][j] = gcd(x, y);
		}
	}
}

ll query(int i, int j) {
	int k = logs[j - i + 1];
	ll x = sparse[i][k];
	ll y = sparse[j - (1 << k) + 1][k];
	return gcd(x, y);
}

int main() {
	optimizar_io
	int tc, n;
	array<ll,200000> a;

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i + 1 < n; i++) {
			diff.emplace_back(abs(a[i] - a[i + 1]));
		}
		int size = diff.size();
		preprocess(size);
		int l = 1, r = n;
		while (l < r) {
			int mid = (l + r) / 2;
			auto check = [&](int k) {
				for (int i = 0; i + k <= size; i++) {
					if (query(i, i + k - 1) > 1)
						return true;
				}
				return false;
			};
			if (check(mid))
				l = mid + 1;
			else
				r = mid;
		}
		cout << l << "\n";
		diff.clear();
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
