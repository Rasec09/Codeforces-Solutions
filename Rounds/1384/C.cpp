#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef vector<int> vi;
vector<vi> ady;
vi visited;

void dfs(int u) {
	visited[u] = true;
	for (int v : ady[u]) {
		if (!visited[v])
			dfs(v);
	}
}

int main() {
	optimizar_io
	int tc, n;
	string s, t;

	cin >> tc;
	while (tc--) {
		cin >> n >> s >> t;
		int node = 0;
		map<int,int> alp;
		set<pair<char,char>> edges;
		bool possible = true;
		for (int i = 0; i < n; i++) {
			if (s[i] > t[i]) {
				possible = false;
				break;
			}
			edges.insert(make_pair(s[i], t[i]));
			if (!alp.count(s[i])) alp[s[i]] = node++;
			if (!alp.count(t[i])) alp[t[i]] = node++;
		}
		if (!possible) {
			cout << "-1\n";
			continue;
		}
		ady.assign(node, vi());
		for (auto e : edges) {
			ady[alp[e.first]].push_back(alp[e.second]);
			ady[alp[e.second]].push_back(alp[e.first]);
		}
		visited.assign(node, 0);
		int numComp = 0;
		for (int i = 0; i < node; i++) {
			if (!visited[i]) {
				dfs(i);
				numComp++;
			}
		}
		cout << alp.size() - numComp << "\n";
	}
	return 0;
}
