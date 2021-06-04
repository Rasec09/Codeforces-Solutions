#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;
typedef vector<int> vi;

vector<vi> ady;
ll l[100010], r[100010], memo[100010][2];

ll dfs(int p, int u, bool flag) {
	if (memo[u][flag] != -1) return memo[u][flag];
	ll sum = 0;
	for (int v : ady[u]) {
		if (v == p) continue;
		ll parentVal = (flag ? r[u] : l[u]);
		sum += max(dfs(u, v, false) + abs(l[v] - parentVal), dfs(u, v, true) + abs(r[v] - parentVal));	
	}
	return memo[u][flag] = sum;
}

int main() {
	optimizar_io
    int tc, n, u, v;

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
		ady.assign(n, vi());
		for (int i = 0; i < n - 1; i++) {
			cin >> u >> v;
			u--; v--;
			ady[u].push_back(v);
			ady[v].push_back(u);
		}
		memset(memo, -1, sizeof(memo));
		cout << max(dfs(-1, 0, false), dfs(-1, 0, true)) << "\n";
	}
	return 0;
}
