#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
  optimizar_io

  int n, l, s[100010];
  vector<int> ini, fin;

  cin >> n;
  for (int sequences = 0; sequences < n; sequences++) {
    cin >> l;
    for (int i = 0; i < l; i++) {
      cin >> s[i];	
    }
    bool flag = true;
    for (int i = 0; i + 1 < l; i++) {
      if (s[i] < s[i + 1]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      ini.push_back(s[0]);
      fin.push_back(s[l - 1]);
    }
  }
  sort(fin.begin(), fin.end());
  ll c = 0, size = ini.size();
  for (int i = 0; i < size; i++) {
    ll pos = lower_bound(fin.begin(), fin.end(), ini[i]) - fin.begin();
    c += size - pos;
  }
  cout << (ll)n * (ll)n - c << "\n";
  return 0;
}
