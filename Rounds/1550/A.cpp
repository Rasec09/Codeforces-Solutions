#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;

int memo[5010][5010];

int steps(int x, int a) {
	if (x == 0) return 0;
	if (x < 0) return 1e9;
	if (memo[x][a] != -1) return memo[x][a]; 
	return memo[x][a] = min({steps(x - a, a), steps(x - a, a + 1), steps(x - a, a + 2)}) + 1;
}

int main() {
	optimizar_io
	int tc, s;
	
	memset(memo, -1, sizeof(memo));
	cin >> tc;
	while (tc--) {
		cin >> s;
		cout << steps(s, 1) << "\n"; 
	}
	return 0;
}
