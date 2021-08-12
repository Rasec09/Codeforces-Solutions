#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
const ll MOD = 1e9 + 7;

ll mod(ll a, ll b) {
	return ((a % b) + b) % b;
}

ll powMod(ll a, ll n, ll m) {
	ll result = 1;
	while (n) {
		if (n & 1)
			result = mod(result * a, m);
		a = mod(a * a, m);
		n >>= 1;
	}
	return result;
}

int main() {
	optimizar_io
	int tc; 
	ll n, k;

	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		if (n & 1) {
			ll ans = mod(powMod(2, n - 1, MOD) + 1, MOD); // nCk(n, 0) + nCk(n, 2) + ... + nCk(n, n - 1);
			ans = powMod(ans, k, MOD);
			cout << ans << "\n";
		}
		else {
			ll numWaysOneBit = mod(powMod(2, n - 1, MOD) - 1, MOD); // nCk(n, 0) + nCk(n, 2) + ... + nCk(n, n - 2);
			ll ans = powMod(numWaysOneBit, k, MOD);
			ll tmp = 1;
			for (int i = 1; i <= k; i++) { // After i bit the remaining k − i bits don't matter
				ans = mod(ans + mod(tmp * powMod(2, n * (k - i), MOD), MOD), MOD);
				tmp = mod(tmp * numWaysOneBit, MOD);
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
/*
n = #elements of array
k + 1 = max size in bits of n

if n es impar:
	And == Xor
	if #unos igual a n:
		&: 1
		^: 1
	else
		&: 0
		^: (#unos es impar ? 1 : 0);	
else
	And >= Xor
	if #unos igual a n:
		&: 1
		^: 0
	else
		&: 0
		^: (#unos es impar ? 1 : 0);
*/
