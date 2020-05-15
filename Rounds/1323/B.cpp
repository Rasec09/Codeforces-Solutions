#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;
typedef pair<int,int> ii;

int rangeSum(vector<int> &a, int i, int j) {
  return i == 0 ? a[j] : a[j] - a[i - 1];
}

int subWindowns(vector<int> &a, int size) {
  if (size > a.size()) return 0;
  int cnt = 0;
  for (int i = 0; i + size <= a.size(); i++) {
    if (rangeSum(a, i, i + size - 1) == size)
      cnt++;
  }
  return cnt;
}

int main() {
  optimizar_io
  int n, m, k;
  vector<int> a, b;
  vector<ii> div;

  cin >> n >> m >> k;
  a.assign(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i)
      a[i] += a[i - 1];
  }
  b.assign(m, 0);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    if (i)
      b[i] += b[i - 1];
  }
  for (int i = 1; i * i <= k; i++) {
    if (k % i == 0) {
      ii d = make_pair(i, k / i);
      div.push_back(d);
    }
  }
  ll ans = 0;
  for (int i = 0; i < div.size(); i++) {
    ll x = subWindowns(a, div[i].first);
    ll y = subWindowns(b, div[i].second);
    ans += x * y; 
    if (div[i].first != div[i].second) {
      x = subWindowns(a, div[i].second);
      y = subWindowns(b, div[i].first);
      ans += x * y;
    }
  }
  cout << ans << "\n";
  return 0;
}
