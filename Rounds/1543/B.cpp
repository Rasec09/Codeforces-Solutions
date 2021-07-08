#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
 
int main() {
	optimizar_io
	int tc, n;
	array<int,200000> a;

	cin >> tc;
	while (tc--) {
		cin >> n;
		ll total = 0;
		for (int i = 0; i < n; i++) cin >> a[i], total += a[i];
		ll rem = total % n;
		cout << (n - rem) * rem << "\n";
	}
	return 0;
}
