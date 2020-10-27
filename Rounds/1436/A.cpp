#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
 
int main() {
	optimizar_io
	int tc, n, m, a[110];
 
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		ll sum = 0;
		for (int i = 0; i < n; i++)  {
			cin >> a[i];
			sum += a[i];
		}
		if (sum == m) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
