#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll; 

ll powMod(ll a, ll n) {
	ll result = 1;
	while (n) {
		if (n & 1)
			result = result * a;
		a = a * a;
		n >>= 1;
	}
	return result;
}

int main() {
	optimizar_io
	ll k;
 	string s = "codeforces"; 

	cin >> k;
	ll pro = 1, a = 2, j = 0;
	while (pro < k) {
		for (int i = 0; i <= 10; i++) {
			//cout << a << " " << i << " " << a - 1 << " " << 10 - i << "\n";
			pro = powMod(a, i) * powMod(a - 1, 10 - i);
			j = i;
			if (pro >= k)
				break; 
		}
		if (pro < k) {
			a++;
		}
	}
	string ans;
	for (int i = 0; i < j; i++) {
		for (int l = 0; l < a; l++)
			ans.push_back(s[i]);
	}
	for (int i = j; i < 10; i++) {
		for (int l = 0; l + 1 < a; l++)
			ans.push_back(s[i]);
	}
	cout << ans << "\n";
	return 0;
}
