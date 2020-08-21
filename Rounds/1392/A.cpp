#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, n, a[200010];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		map<int,int> freq;
		for (int i = 0; i < n; i++)
			freq[a[i]]++;
		if (freq.size() == 1)
			cout << n << "\n";
		else
			cout << 1 << "\n";
	}
	return 0;
}
