#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
  optimizar_io

  int t, n;
  string s;

  cin >> t;
  while (t--) {
    cin >> n >> s;
    int sum = 0, impar = (s[n - 1] - '0') & 1;
    for (int i = n - 1; i >= 0; i--) {
      sum += (s[i] - '0');
    }
    if (sum % 2 == 0 and impar) {
      cout << s << "\n";
      continue;
    }
    int d = s[n - 1] - '0';
    while (!s.empty() and d % 2 == 0) {
      sum -= (s.back() - '0'); 
      s.pop_back();
      d = s.back() - '0';
    }
    //cout << sum << " " << s << "\n";
    n = s.size();
    if (sum % 2 != 0) {
      for (int i = n - 2; i >= 0; i--) {
        d = s[i] - '0';
        if (d & 1) {
          sum -= d; 
          s.erase(i, 1);
          break;
        }
      }
    }
    if (sum % 2 != 0 or s.empty())
      cout << "-1\n";
    else
      cout << s << "\n";
  }
  return 0;
}
