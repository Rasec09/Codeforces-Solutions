#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
	
typedef long long int ll;
typedef vector<ll> vi;
	
int main() {
	optimizar_io
	int tc, n, u[200010], s[200010]; 
	
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> u[i];
		for (int i = 0; i < n; i++) cin >> s[i];
		int x = 0;
		map<int,int> hash;
		for (int i = 0; i < n; i++) {
			if (!hash.count(u[i])) {
				hash[u[i]] = ++x;
			}
		}
		vector<pair<ll,int>> students;
		for (int i = 0; i < n; i++) {
			u[i] = hash[u[i]];
			students.push_back(make_pair(s[i], u[i] - 1));
		}
		sort(students.begin(), students.end(), greater<pair<ll,int>>());
		vector<vi> uni(hash.size(), vi());
		for (int i = 0; i < n; i++) {
			uni[students[i].second].push_back(students[i].first);
		}
		for (int i = 0; i < uni.size(); i++) {
			for (int j = 1; j < uni[i].size(); j++) {
				uni[i][j] += uni[i][j - 1];
			}
		}
		vector<ll> ans(n, 0);
		for (int i = 0; i < uni.size(); i++) {
			for (int k = 1; k <= uni[i].size(); k++) {
				int size = uni[i].size();
				int rem = size % k;
				ans[k - 1] += uni[i][size - rem - 1];
			}
		}
		for (auto a : ans) cout << a << " ";
		cout << "\n";
	}
	return 0;
}
