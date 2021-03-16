#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
    int n, a[200010];

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<pair<int,int>> mp(5000010, make_pair(-1,-1));
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int sum = a[i] + a[j];
			if (mp[sum].first != -1) {
				if (mp[sum].first != i and mp[sum].second != i and mp[sum].first != j and mp[sum].second != j) {
					cout << "YES\n" << ++mp[sum].first << " " << ++mp[sum].second << " " << ++i << " " << ++j;
					return 0;
				}
			}
			else {
				mp[sum] = make_pair(i, j);
			}
		}
	}
	cout << "NO\n";
	return 0;
}
