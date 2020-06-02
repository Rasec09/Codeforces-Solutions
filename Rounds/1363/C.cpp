#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef vector<int> vi;
vector<vi> ady;
vi dist;

int dfs(int p, int u) {
	int size = 1;
	for (auto v : ady[u]) {
		if (v != p) {
			size += dfs(u, v);
		}
	}
	return dist[u] = size;
}

int main() {
    optimizar_io
 	int tc, n, x, u, v;

 	cin >> tc;
 	while (tc--) {
 		cin >> n >> x; x--;
 		ady.assign(n, vi());
 		for (int i = 0; i < n - 1; i++) {
 			cin >> u >> v;
 			u--; v--;
 			ady[u].push_back(v);
 			ady[v].push_back(u);
 		}
 		if (ady[x].size() <= 1) {
 			cout << "Ayush\n";
 			continue;
 		}
 		//dist.assign(n, 0);
 		//dfs(x, x);
 		cout << (n & 1 ? "Ashish\n" : "Ayush\n");
 	}
    return 0;
}
