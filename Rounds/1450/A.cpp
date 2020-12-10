#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
  optimizar_io
  int tc, n;
  string s;

  cin >> tc;
  while (tc--) {
    cin >> n >> s;
    sort(s.begin(), s.end());
    cout << s << "\n";
  }
  return 0;
}
