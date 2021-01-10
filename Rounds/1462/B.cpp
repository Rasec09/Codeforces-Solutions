#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

void solve(int n, string &s) {
  if (s == "2020") {
    cout << "YES\n";
    return;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (n - (j - i + 1) == 4) {
        string tmp;
        for (int k = 0; k < n; k++) {
          if (k >= i and k <= j)
            continue;
          tmp.push_back(s[k]);
        }
        if (tmp == "2020") {
          cout << "YES\n";
          return;
        }
      }
    }
  }
  cout << "NO\n";
}

int main() {
  optimizar_io
  int tc, n;
  string s;

  cin >> tc;
  while (tc--) {
    cin >> n >> s;
    solve(n, s);		
  }
  return 0;
}
