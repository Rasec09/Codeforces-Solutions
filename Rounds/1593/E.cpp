#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;

vector<vector<int>> graph;

int main() {
	optimizar_io
	int tc, n, k, u, v;

	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		graph.assign(n, vector<int>());
		for (int i = 0; i < n - 1; i++) {
			cin >> u >> v;
			u--; v--;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		vector<int> visited(n), dist(n), rem(n);
		queue<int> q;
		for (int i = 0; i < n; i++) {
			if (graph[i].size() == 1) {
				visited[i] = true;
				dist[i] = 1;
				q.push(i);
			}
			rem[i] = graph[i].size();
		}
		int rounds = 0;
		while (!q.empty()) {
			int next = q.front();
			q.pop();
			for (auto v : graph[next]) {
				rem[v]--;
				if (rem[v] == 1 and !visited[v]) {
					visited[v] = true;
					dist[v] = dist[next] + 1;
					q.push(v);
				}
			}
			rounds++;
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (dist[i] > k)
				ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
