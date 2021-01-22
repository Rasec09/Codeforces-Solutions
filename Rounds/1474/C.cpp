#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

vector<pair<int,int>> ans;

bool test(int x, int a[], int n) {
	map<int,int> mp;
	for (int i = 0; i < n; i++) mp[a[i]]++;
	ans.clear();
	while (mp.size()) {
		auto it = mp.rbegin();
		int y = it -> first;
		int need = x - y;
		// cout << y << " " << need << "\n";
		if (mp.count(need)) {
			x = max(need, y);
			mp[y]--;
			if (mp[y] == 0)
				mp.erase(y);
			mp[need]--;
			if (mp[need] == 0)
				mp.erase(need);
			ans.push_back(make_pair(y, need));
		}
		else {
			return false;
		}
	}
	return true;
}

void solve(int a[], int n) {
	for (int j = n - 1; j > 0; j--) {
		int x = a[0] + a[j];
		if (test(x, a, n)) {
			cout << "YES\n" << x << "\n";
			for (auto p : ans)
				cout << p.first << " " << p.second << "\n";
			return;
		}
	}
	cout << "NO\n";
	return;
}

int main() {
	optimizar_io
	int tc, n, a[2010];

	cin >> tc;
	while (tc--) {
		cin >> n;
		n *= 2;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n, greater<int>());
		solve(a, n);
	}
	return 0;
}
