#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int findMin(ll a[], int n, int l, int r) {
  int idx = l;
  for (int i = l; i <= r; i++) {
    if (a[i] < a[idx]) {
      idx = i;
    }
  }
  return idx;
}

ll maxSum;
vector<ll> ans;

void search(ll a[], ll b[], int n, int l, int r) {
  if (l > r) {
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      sum += b[i];
    }
    if (sum > maxSum) {
      maxSum = sum;
      for (int i = 0; i < n; i++)
        ans[i] = b[i]; 
    }
  }
  else {
    int idx = findMin(a, n, l, r);
    for (int i = l; i <= idx; i++)
      b[i] = a[idx];
    search(a, b, n, idx + 1, r);
    for (int i = idx; i <= r; i++)
      b[i] = a[idx];
    search(a, b, n, l, idx - 1);
  }
}

int main() {
  optimizar_io

  int n; 
  ll a[1010], b[1010];

  cin >> n;
  ans.assign(n, 0);
  for (int i = 0; i < n; i++) cin >> a[i];
  maxSum = -1;
  search(a, b, n, 0, n - 1);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << "\n";
  return 0;
}
