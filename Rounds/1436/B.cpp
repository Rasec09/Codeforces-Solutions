#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;
typedef vector<ll> vi;

int n, finish;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound) {
  ll sieveSize = upperbound + 1;
  bs.set();
  bs[0] = bs[1] = 0;
  for (ll i = 2; i <= sieveSize; i++) {
    if (bs[i]) {
      for (ll j = i * i; j <= sieveSize; j += i)
        bs[j] = 0;
      primes.push_back(i);
    }
  }
}

int next(int n) {
  for (int k = n + 1; k <= 100000; k++) {
    if (bs[k]) {
      int next = k - n;
      if (!bs[next])
        return next;
    }
  }
  return -1;
}

int main() {
  optimizar_io
  int tc;

  sieve(100000);
  cin >> tc;
  while (tc--) {
    cin >> n;
    if (bs[n]) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
          cout << "1 ";
        cout << "\n";
      }
    }
    else {
      vector<vector<int>> s(n, vector<int>(n, 0));
      for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++)
          s[i][j] = 1;
      }
      int x = next(n - 1);
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (i == n - 1 and j == n - 1)
            continue;
          if (s[i][j] == 0)
            s[i][j] = x;
        }
      }
      s[n - 1][n - 1] = next(x * (n - 1));
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
          cout << s[i][j] << " ";
        cout << "\n";
      }
    }
  }
  return 0;
}
