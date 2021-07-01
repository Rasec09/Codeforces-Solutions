#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;
typedef vector<int> vi;

vector<vi> ady;
vi color;

bool bicolorable(int src) {
	queue<int> q;
	q.push(src);
	color[src] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int &v : ady[u]) {
			if (color[v] == -1) {
				color[v] = 1 - color[u];
				q.push(v);
			}
			else if (color[v] == color[u]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	optimizar_io
	int tc, n, m, v[200010], t[200010], a[200010];

	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> v[i];
		for (int i = 0; i < n; i++) cin >> t[i];
		ady.assign(n, vi());
		color.assign(n, -1);
		while (m--) {
			int a, b;
			cin >> a >> b;
			a--; b--;
			ady[a].push_back(b);
			ady[b].push_back(a);
		}
		int sum = 0;
		for (int i = 0; i < n; i++) {
			a[i] = v[i] - t[i];
			sum += a[i];
		}
		if (sum & 1) {
			cout << "NO\n";
		}
		else {
			if (bicolorable(0)) {
				ll red = 0, blue = 0;
				for (int i = 0; i < n; i++) {
					if (color[i])
						red += a[i];
					else
						blue += a[i];
				}
				cout << (red == blue ? "YES" : "NO") << "\n";
			}
			else {
				cout << "YES\n";
			}
		}
	}
	return 0;
}
