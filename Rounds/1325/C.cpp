#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef pair<int,int> ii;
typedef vector<int> vi;

vector<vi> ady;

int main() {
  optimizar_io
  int n, u, v;
  map<ii,int> idx; 
  vector<int> ans;

  cin >> n;
  ady.assign(n, vi());
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    if (u > v) swap(u, v);
    u--; v--;
    idx[ii(u, v)] = i;
    ady[u].push_back(v);
    ady[v].push_back(u);
  }
  int cnt = 0;
  ans.assign(n - 1, -1);
  for (int i = 0; i < ady.size(); i++) {
    if (ady[i].size() >= 3) {
      for (int j = 0; j < 3; j++) {
        u = i;
        v = ady[i][j];
        if (u > v) swap(u, v);
        ans[idx[ii(u,v)]] = cnt;
        cnt++;
      }
      break;
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    if (ans[i] == -1) {
      ans[i] = cnt;
      cnt++;
    }
    cout << ans[i] << "\n";
  }
  return 0;
}
