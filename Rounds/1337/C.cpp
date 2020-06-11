#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;
typedef vector<int> vi;

vector<vi> ady;
vi level, size;

int dfs(int p, int u) {
	int cnt = 1;
	for (int v : ady[u]) {
		if (v != p) {
			level[v] = level[u] + 1;
			cnt += dfs(u, v);
		}
	}
	return size[u] = cnt;
}

int main() {
    optimizar_io 
    int n, k, u, v;

    cin >> n >> k;
    ady.assign(n, vi());
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--; v--;
        ady[u].push_back(v);
        ady[v].push_back(u);
    }
    level.assign(n, 1);
    size.assign(n, 0);
    dfs(0, 0);
    vi diff;
    for (int i = 0; i < n; i++)
    	diff.push_back(level[i] - size[i]);
    sort(diff.begin(), diff.end(), greater<int>());
    ll ans = 0;
    for (int i = 0; i < k; i++)
    	ans += diff[i];
    cout << ans << "\n";
    return 0;
}
