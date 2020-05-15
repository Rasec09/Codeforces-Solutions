#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef vector<int> vi;

int n, a[200010], dp[200010], ans[200010];
vector<vi> ady;

void dfs1(int from, int u) {
  dp[u] = a[u];
  for (auto v : ady[u]) {
    if (v != from) {
      dfs1(u, v);
      dp[u] += max(0, dp[v]);
    }
  }
}

void dfs2(int from, int u) {
  ans[u] = dp[u];
  if (from != -1) {
    int val = ans[from] - max(0, dp[u]);
    ans[u] += max(0, val);
  }
  for (auto v : ady[u]) {
    if (v != from)
      dfs2(u, v);
  }
}

int main() {
  optimizar_io
  int u, v;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (!a[i])
      a[i] = -1;
  }
  ady.assign(n, vi());
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    u--; v--;
    ady[u].push_back(v);
    ady[v].push_back(u);
  }
  dfs1(-1, 0);
  dfs2(-1, 0);
  for (int i = 0; i < n; i++)
    cout << ans[i] << " ";
  cout << "\n";
  return 0;
}
