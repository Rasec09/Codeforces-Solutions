#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef vector<int> vi;

vector<vi> AdjList;
vi dfs_low, dfs_num, Stack, visited;
int dfsContador, numSCC;

vector<vi> scc;

void tarjanSCC(int u) {
	dfs_low[u] = dfs_num[u] = dfsContador++;
	Stack.push_back(u);
	visited[u] = 1;
	for (int i = 0; i < AdjList[u].size(); i++) {
		int v = AdjList[u][i];
		if (dfs_num[v] == -1)
			tarjanSCC(v);
		if (visited[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	if (dfs_low[u] == dfs_num[u]) {
		++numSCC;
		vi componente;
		while (1) {
			int v = Stack.back(); Stack.pop_back();
			visited[v] = 0;
			componente.push_back(v);
			if (u == v) break;
		}
		scc.push_back(componente);
	}
}

int main() {
	optimizar_io
	int tc, n;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> n >> s;
		AdjList.assign(n, vi());
		for (int i = 0; i < n; i++) {
			if (s[i] == '-') {
				AdjList[i].push_back((i + 1) % n);
				AdjList[(i + 1) % n].push_back(i);
			}
			else if (s[i] == '>') {
				AdjList[i].push_back((i + 1) % n);
			}
			else {
				AdjList[(i + 1) % n].push_back(i);
			}
		}
		dfsContador = numSCC = 0;
		dfs_num.assign(n, -1);
		dfs_low.assign(n, 0);
		visited.assign(n, 0);
		for (int i = 0; i < n; i++)
			if (dfs_num[i] == -1)
				tarjanSCC(i);
		
		int ans = 0;
		for (int i = 0; i < scc.size(); i++) {
			if (scc[i].size() > 1)
				ans += scc[i].size();
		}
		cout << ans << "\n";
		scc.clear();
	}
	return 0;
}
