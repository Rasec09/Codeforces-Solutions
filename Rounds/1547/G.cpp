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

void dfs(int u) {
	visited[u] = true;
	for (auto v : AdjList[u]) {
		if (!visited[v])
			dfs(v);
	}
}

vi topologicalSort(vector<vi> &AdjList, int V) {
	vi orden;
	vi in_degree(V, 0);
 
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < AdjList[i].size(); j++) {
			in_degree[AdjList[i][j]]++;
		}
	}
 
	priority_queue<int, vector<int>, greater<int> > q;
	for (int i = 0; i < V; i++)
		if (in_degree[i] == 0)
			q.push(i);
 
	while (!q.empty()) {
		int v = q.top();
		q.pop();
		orden.push_back(v);
		for (int i = 0; i < AdjList[v].size(); i++) {
			in_degree[AdjList[v][i]]--;
			if (in_degree[AdjList[v][i]] == 0)
				q.push(AdjList[v][i]);
		}
	}
	return orden;
}

vector<vi> condensedGraph(vector<vi> &adj, vector<vi> &scc, int n) {
	vector<vi> adj_scc;
	set<pair<int,int>> edges;
	map<int,int> vertexSCC;

	for (int i = 0; i < scc.size(); i++) {
		for (int v : scc[i]) {
			vertexSCC[v] = i;
		}
	}

	for (int i = 0; i < adj.size(); i++) {
		for (int v : adj[i]) {
			if (vertexSCC[i] != vertexSCC[v])
				edges.insert(make_pair(vertexSCC[i], vertexSCC[v]));
		}
	}
	adj_scc.assign(scc.size(), vi());
	for (auto e : edges) {
		adj_scc[e.first].push_back(e.second);
	}
	return adj_scc;
}

int main() {
	optimizar_io
	int tc, n, m, a, b;

	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		AdjList.assign(n, vi());
		vector<int> loop(n);
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			a--; b--;
			if (a != b)
				AdjList[a].push_back(b);
			else
				loop[a] = 1;
		}
		dfsContador = numSCC = 0;
		dfs_num.assign(n, -1);
		dfs_low.assign(n, 0);
		visited.assign(n, 0);
		scc.clear();

		for (int i = 0; i < n; i++)
			if (dfs_num[i] == -1)
				tarjanSCC(i);

		reverse(scc.begin(), scc.end());

		map<int,int> vertexSCC;
		for (int i = 0; i < scc.size(); i++) {
			for (int v : scc[i])
				vertexSCC[v] = i;
		}

		vector<vi> adj_scc = condensedGraph(AdjList, scc, n);
		vi topoSort = topologicalSort(adj_scc, adj_scc.size());
		
		int idx = 0;
		for (int i = 0; i < topoSort.size(); i++) {
			if (topoSort[i] == vertexSCC[0]) {
				idx = i;
				break;
			}
		}

		vi numPaths;
		numPaths.assign(numSCC, 0);
		numPaths[idx] = 1;
		for (int i = idx; i < topoSort.size(); i++) {
			if (scc[topoSort[i]].size() > 1) {
				numPaths[topoSort[i]] = 1e9;
			}
		}
		dfs(0);
		for (int i = 0; i < n; i++) {
			if (loop[i] and visited[i])
				numPaths[vertexSCC[i]] = 1e9;
		}
		for (int i = idx; i < topoSort.size(); i++) {
			int u = topoSort[i];
			for (int j = 0; j < adj_scc[u].size(); j++) {
				int v = adj_scc[u][j];
				if (numPaths[v] == 1e9) continue;
				if (numPaths[u] == 1e9)
					numPaths[v] = 1e9;
				else
					numPaths[v] = min(numPaths[v] + numPaths[u], 2);
			}
		}

		vector<int> ans(n);
		for (int i = 0; i < numPaths.size(); i++) {
			for (int j = 0; j < scc[i].size(); j++) {
				if (numPaths[i] == 1e9)
					ans[scc[i][j]] = -1;
				else
					ans[scc[i][j]] = numPaths[i];				
			}
		}

		for (auto x : ans) cout << x << " ";
		cout << "\n";
	}
	return 0;
}
