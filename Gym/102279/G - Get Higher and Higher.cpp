#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef vector<int> vi;
vector<int> dist;

void bfs(vector<vi> &ady, int s, int n) {	
	queue<int> q;
	q.push(s);
	dist.assign(n, -1);
	dist[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < ady[u].size(); ++i) {
			int v = ady[u][i];
			if (dist[v] == -1) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
}

int getDiameter(vector<vi> &ady, int n) {
	bfs(ady, 0, n);
	int a = 0, b;
	for (int i = 0; i < n; ++i) {
		if (dist[i] > a){
			a = dist[i];
			b = i;
		}
	}
	bfs(ady, b, n);
	int diam = 0;
	for (int i = 0; i < n; ++i) {
		diam = max(diam, dist[i]);
	}
	return diam;
}

int main() {
    optimizar_io
    int n, m, u, v;
    vector<vi> tree1, tree2;

    cin >> n;
    tree1.assign(n, vi());
    for (int i = 0; i < n - 1; i++) {
    	cin >> u >> v;
    	u--; v--;
    	tree1[u].push_back(v);
    	tree1[v].push_back(u);
    }
    cin >> m;
    tree2.assign(m, vi());
    for (int i = 0; i < m - 1; i++) {
    	cin >> u >> v;
    	u--; v--;
    	tree2[u].push_back(v);
    	tree2[v].push_back(u);
    }
    int d1 = getDiameter(tree1, n);
    int d2 = (getDiameter(tree2, m) + 1) / 2;
    cout << (d1 > d2 ? "GGEZ\n" : "FF\n");
    return 0;
}
