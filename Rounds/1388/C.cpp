#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef vector<int> vi;

int h[100010], p[100010];
vector<vi> ady;
vi subTree;

int dfs(int from, int u) {
	int size = p[u];
	for (int v : ady[u]) {
		if (v != from)
			size += dfs(u, v);
	}
	return subTree[u] = size;
}

int main() {
	optimizar_io
	int tc, n, m;

	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> p[i];
		for (int i = 0; i < n; i++) cin >> h[i];
		int u, v;
		ady.assign(n, vi());
		for (int i = 0; i < n - 1; i++) {
			cin >> u >> v;
			u--; v--;
			ady[u].push_back(v);
			ady[v].push_back(u);
		}
		subTree.assign(n, 0);
		dfs(0, 0);
		bool possible = true;
		vi g(n);
		for (int i = 0; i < n; i++) {
			if ((subTree[i] + h[i]) % 2) {
				possible = false;
				break;
			}
			g[i] = (subTree[i] + h[i]) / 2;
			if (g[i] > subTree[i] or g[i] < 0) {
				possible = false;
				break;
			}
		}
		if (!possible) {
			cout << "NO\n";
			continue;
		}
		function<void(int,int)> dfs1 = [&](int from, int u) {
			int total = 0;
			for (int v : ady[u]) {
				if (v != from)
					total += g[v];
			}
			possible &= (g[u] >= total);
			for (int v : ady[u]) {
				if (v != from)
					dfs1(u, v);
			}
		};
		dfs1(0, 0);
		cout << (possible ? "YES\n" : "NO\n");
	}
	return 0;
}
