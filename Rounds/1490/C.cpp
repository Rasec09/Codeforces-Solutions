#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
    int tc;
	ll x;
	vector<ll> cubes;

	for (ll i = 1; i * i * i <= 1e12; i++) {
		cubes.push_back(i * i * i);
	}
	cin >> tc;
	while (tc--) {
		cin >> x;
		bool possible = false;
		for (int i = 0; i < cubes.size(); i++) {
			ll y = x - cubes[i];
			if (y < 0) continue;
			if (binary_search(cubes.begin(), cubes.end(), y)) {
				possible = true;
				break;
			}
		}
		cout << (possible ? "YES\n" : "NO\n");	
	}
	return 0;
}
