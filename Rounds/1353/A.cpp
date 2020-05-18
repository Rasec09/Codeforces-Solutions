#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
int main() {
    optimizar_io
 	int tc, n, m;

 	cin >> tc;
 	while (tc--) {
 		cin >> n >> m;
 		if (n == 1)
 			cout << "0\n";
 		else if (n == 2)
 			cout << m << "\n";
 		else
 			cout << 2 * m << "\n";
 	}
    return 0;
}
