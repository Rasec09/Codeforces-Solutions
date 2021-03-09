#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;

vector<vii> Ady;
vi dist;

void addEdge(int u, int v, int w) {
	Ady[u * 51].push_back(ii(v * 51 + w, 0));
	for (int i = 1; i <= 50; i++)
		Ady[u * 51 + i].push_back(ii(v * 51, (i + w) * (i + w)));
}

void dijkstra(int s) {
	dist[s] = 0;
	priority_queue<ii,vector<ii>,greater<ii>> pq;
	pq.push(ii(0, s));
	while (!pq.empty()) {
		ii front = pq.top();
		pq.pop();
		int d = front.first, u = front.second;
		if (d > dist[u]) continue;
		for (auto v : Ady[u]) {
			if (dist[u] + v.second < dist[v.first]) {
				dist[v.first] = dist[u] + v.second;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}
}

int main() {
	optimizar_io
	int V, E, a, b, w;

	cin >> V >> E;
	Ady.assign(V * 51, vii());
	dist.assign(Ady.size(), INF);
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> w;
		a--; b--;
		addEdge(a, b, w);
		addEdge(b, a, w);
	}
	dijkstra(0);
	for (int i = 0; i < V; i++) cout << (dist[i * 51] == INF ? -1 : dist[i * 51]) << " ";
	cout << "\n";
	return 0;
}
