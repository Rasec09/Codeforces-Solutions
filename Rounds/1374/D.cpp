#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, n, k, a[200010];
	map<int,int> freq;
	set<ll> mySet;

	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			freq[a[i] % k]++;
		}
		for (auto f : freq) {
			if (f.first != 0) {
				ll x = k - f.first;
				x += (1LL * k * (f.second-1));
				mySet.insert(x);
			}
		}
		if (mySet.empty())
			cout << "0\n";
		else {
			cout << *mySet.rbegin() + 1 << "\n";
		}
		mySet.clear();
		freq.clear();
	}
	return 0;
}
