#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
    int tc, n, a[105];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		map<int,int> freq;
		for (int i = 0; i < n; i++) freq[a[i]]++;
		for (int i = 0; i < n; i++) {
			if (freq[a[i]] == 1) {
				cout << i + 1 << "\n";
				break;
			}
		}
	}
	return 0;
}
