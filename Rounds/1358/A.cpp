#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
    optimizar_io
    int tc, n, m;

    cin >> tc;
    while (tc--) {
    	cin >> n >> m;
    	if (n > m) swap(n, m);
    	int total = 0;
    	total += (m / 2) * n;
    	total += (m % 2) * ((n + 1)/ 2);
    	cout << total << "\n";
    }
    return 0;
}
