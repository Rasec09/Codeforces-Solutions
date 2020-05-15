#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
    optimizar_io
    int t, n, k;

    cin >> t;
    while (t--) {
    	cin >> n >> k;
    	int raiz = sqrt(n);
    	if (k > raiz) {
			cout << "NO";
		}
		else {
			if (k % 2 == n % 2)
				cout << "YES";
			else
				cout << "NO";
		}
    	cout << "\n";
    }
    return 0;
}
