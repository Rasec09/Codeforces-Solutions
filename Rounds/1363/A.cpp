#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

bool solve(int a[], int n, int x) {
	int par = 0, impar = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] & 1)
			impar++;
		else
			par++;
	}
	for (int i = 1; i <= x; i++) {
		int need = x - i;
		if ((i & 1) and impar >= i and par >= need)
			return true;
	}
	return false;
}

int main() {
    optimizar_io
 	int tc, n, x, a[1010];

 	cin >> tc;
 	while (tc--) {
 		cin >> n >> x;
 		for (int i = 0; i < n; i++) cin >> a[i];
  		cout << (solve(a, n, x) ? "Yes\n" : "No\n");
  	}
    return 0;
}
