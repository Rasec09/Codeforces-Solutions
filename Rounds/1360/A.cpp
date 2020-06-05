#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
    optimizar_io
    int tc, a, b;

    cin >> tc;
    while (tc--) {
    	cin >> a >> b;
    	cout << min(max(4 * a * a, b * b), max(4 * b * b, a * a)) << "\n";
    }
    return 0;
}
