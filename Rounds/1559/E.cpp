#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
const ll mod = 998244353;
int n, m, l[100010], r[100010];

ll dp(int g) {
	int S = m / g;
	vector<vector<ll>> ways(n + 1, vector<ll>(S + 1)); // ways[i][j] = numero de sequencias con los primeros i elementos con suma igual a j
	
	ways[0][0] = 1; 
	for (int i = 1; i <= n; i++) {
		int L = (l[i] + g - 1) / g;
		int R = r[i] / g;
		if (L > R) return 0;

		vector<ll> prefix(S + 1);
		for (int j = 0; j <= S; j++) { // Construir prefix sum array 
			prefix[j] = ways[i - 1][j];
			if (j)
				prefix[j] += prefix[j - 1];
			prefix[j] %= mod;
		}
		for (int j = 0; j <= S; j++) { // Usamos el prefix sum para optimizar la dp
			int add = (j - L >= 0 ? prefix[j - L] : 0);
      int sub = (j - R - 1 >= 0 ? prefix[j - R - 1] : 0);
      ways[i][j] = (add - sub + mod) % mod;
		}
	}
	ll total = 0;
	for (int sum = 0; sum <= S; sum++) // Agregamos la solucion para cada suma 
		total = (total + ways[n][sum]) % mod;
	return total;
}

int main() {
	optimizar_io
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
	
	vector<int> ans(m + 1);
	for (int i = 1; i <= m; i++) // Calculamos para cada uno de los gcd, 1, 2 ...
		ans[i] = dp(i);
	
	for (int g = m; g > 0; g--) { // Usamos inclusion-exclusion para desacernos de las respuestas a los multiples de g mayores a 1
		for (int j = 2 * g; j <= m; j += g) {
			ans[g] = (ans[g] - ans[j] + mod) % mod;
		}
	}
	cout << ans[1] <<"\n";
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
