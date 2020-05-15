#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

bool palimdromo(string &s, string &t) {
  int n = s.size();
  for (int i = 0, j = n - 1; i < n; i++, j--) {
    if (s[i] != t[j])
      return false;
  }
  return true;
}

bool es_palimdromo(string &s) {
  int n = s.size();
  for (int i = 0, j = n - 1; i < j; i++, j--) {
    if (s[i] != s[j])
      return false;
  }
  return true;
}

int main() {
  optimizar_io

  int n, m;
  string s[110];
  vector<int> v1, v2;
  set<int> idx;

  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> s[i];

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (palimdromo(s[i], s[j])) {
        v1.push_back(i);
        idx.insert(i);
        v2.push_back(j);
        idx.insert(j);
      }
    }
  }
  string ans;
  for (int i = 0; i < v1.size(); i++)
    ans += s[v1[i]];
  int j = -1;
  for (int i = 0; i < n; i++) {
    if (idx.count(i) == 0 and es_palimdromo(s[i])) {
      j = i;
      break;
    }
  }
  if (j != -1)
    ans += s[j];
  for (int i = (int)v2.size() - 1; i >= 0; i--)
    ans += s[v2[i]];
  cout << ans.size() << "\n" << ans << "\n";
  return 0;
}
