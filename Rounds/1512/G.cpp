#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int divSum[10000010];
vector<int> mp;

int main() {
	optimizar_io
    int tc, c, limit = 1e7;

	for (int i = 1; i <= limit; i++) {
		divSum[i] = 1;
	}
	for (int i = 2; i <= limit; i++) {
		for (int j = i; j <= limit; j += i)
			divSum[j] += i;
	}
	mp.assign(*max_element(divSum, divSum + limit + 1) + 1, -1);
	for (int i = 1; i <= limit; i++) {
		if (mp[divSum[i]] == -1)
			mp[divSum[i]] = i;
	}
	cin >> tc;
	while (tc--) {
		cin >> c;
		cout << mp[c] << "\n";
	}
	return 0;
}
