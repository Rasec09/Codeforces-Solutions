#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef vector<int> vi;

vector<vi> AdjList;
vi dfs_num, topologicalSort, visited;

void OrdenTopologico(int u) {
	dfs_num[u] = 1;
	for (int i = 0; i < AdjList[u].size(); ++i) {
		int v = AdjList[u][i];
		if (dfs_num[v] == -1)
			OrdenTopologico(v);
	}
	topologicalSort.push_back(u);
}

void dfs(int u) {
	visited[u] = true;
	for (auto v : AdjList[u]) {
		if (!visited[v])
			dfs(v);
	}
}

int main() {
	optimizar_io
	int tc, n, V;
	array<int,10000> a;

	cin >> tc;
	while (tc--) {
		cin >> n;
		V = n + 1;
		for (int i = 0; i < n; i++) cin >> a[i];
		AdjList.assign(V, vi());
		for (int i = 0; i + 1 < n; i++) {
			AdjList[i].push_back(i + 1);
		}
		for (int i = 0; i < n; i++) {
			if (a[i])
				AdjList[n].push_back(i);
			else
				AdjList[i].push_back(n);
		}
		dfs_num.assign(V, -1);
		topologicalSort.clear();
		for (int i = 0; i < V; ++i) {
			if (dfs_num[i] == -1)
				OrdenTopologico(i);
		}
		reverse(topologicalSort.begin(), topologicalSort.end());
		visited.assign(V, false);
		dfs(topologicalSort[0]);
		if (count(visited.begin(), visited.end(), false)) {
			cout << "-1\n";
		}
		else {
			for (int i = 0; i < V; i++)
				cout << topologicalSort[i] + 1 << " ";
			cout << "\n";
		}
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
