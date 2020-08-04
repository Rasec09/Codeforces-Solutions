#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;
typedef vector<int> vi;
vector<vi> ady;
vi dfs_num;

void dfs(vi &comp, int u) {
	dfs_num[u] = 1;
	for (int v : ady[u]) {
		if (!dfs_num[v])
			dfs(comp, v);
	}
	comp.push_back(u);
}

int main() {
	optimizar_io
	int n, b[200010];
	ll a[200010];

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	ady.assign(n, vi());
	for (int i = 0; i < n; i++) {
		if (b[i] != -1)
			ady[i].push_back(b[i] - 1);
	}
	dfs_num.assign(n, 0);
	vi orden, comp;
	for (int i = 0; i < n; i++) {
		if (!dfs_num[i]) {
			dfs(comp, i);
		}
	}
	reverse(comp.begin(), comp.end());
	dfs_num.assign(n, 0);
	for (int i = 0; i < n; i++) {
		if (a[comp[i]] > 0 and b[comp[i]] != -1) {
			a[b[comp[i]] - 1] += a[comp[i]];
			orden.push_back(comp[i]);
			dfs_num[comp[i]] = 1;
		}
	}
	for (int i = int(comp.size()) - 1; i >= 0; i--) {
		if (!dfs_num[comp[i]])
			orden.push_back(comp[i]);
	}
	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans += a[i];
	cout << ans << "\n";
	for (int x : orden)
		cout << x + 1 << " ";
	cout << "\n";
	return 0;
}
