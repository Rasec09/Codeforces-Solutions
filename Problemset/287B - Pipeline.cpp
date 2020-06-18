#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

bool check(ll n, ll k, ll m, ll total) {
	ll x = k - m;
	ll sum = (x * (x + 1)) / 2;
	return (total - sum) >= n; 
}

int main() {
    optimizar_io
 	ll n, k;

 	cin >> n >> k;
 	if (n == 1) return cout << "0\n", 0;
 	ll total = (k * (k - 1)) / 2 + 1;
 	if (n > total) return cout << "-1\n", 0;
 	if (n <= k) return cout << "1\n", 0;
 	ll low = 2, hig = k - 1;
 	while (low < hig) {
 		ll mid = low + (hig - low) / 2;
		if (check(n, k - 1, mid, total))
			hig = mid;
		else
			low = mid + 1;
 	}
 	cout << low << "\n";
    return 0;
}
