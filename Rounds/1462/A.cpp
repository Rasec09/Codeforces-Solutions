#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
  optimizar_io
  int tc, n, x;

  cin >> tc;
  while (tc--) {
    cin >> n;
    deque<int> dq;
    for (int i = 0; i < n; i++) {
      cin >> x;
      dq.push_back(x);
    }
    vector<int> ans;
    while (!dq.empty()) {
      ans.push_back(dq.front());
      dq.pop_front();
      if (!dq.empty()) {
        ans.push_back(dq.back());
        dq.pop_back();
      }
    }
    for (auto a : ans)
      cout << a << " ";
    cout << "\n";
  }
  return 0;
}
