#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
  optimizar_io
    int tc;
  string s;

  cin >> tc;
  while (tc--) {
    cin >> s;
    int n = s.size();
    for (int i = 1; i < n; i += 2) {
      if (s[i] == '1')
        s[i] = '0';
      else if (s[i] == '0')
        s[i] = '1';
    }
    ll ans = 0;
    map<char,int> cnt;
    cnt[s[0]] = 1;
    int l = 0, r = 0;
    while (r < n) {
      if (cnt['0'] and cnt['1']) {
        cnt[s[l]]--;
        l++;
      }
      else {
        ans += (r - l + 1);
        cnt[s[r + 1]]++;
        r++;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
