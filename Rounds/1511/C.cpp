#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef pair<int,int> ii;

int main() {
	optimizar_io
    int n, q, a[300010], t[300010];
	vector<ii> v;
	set<int> colors;

	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < q; i++) cin >> t[i];
	for (int i = 0; i < n; i++) {
		if (!colors.count(a[i])) {
			v.push_back(ii(a[i], i + 1));
			colors.insert(a[i]);
		}
	}
	vector<int> ans;
	for (int i = 0; i < q; i++) {
		int pos;
		for (int j = 0; j < v.size(); j++) {
			if (t[i] == v[j].first) {
				pos = j;
				break;
			}
		}
		ans.push_back(v[pos].second);
		for (int j = 0; j < v.size(); j++) {
			if (v[j].second < v[pos].second)
				v[j].second++;
		}
		v[pos].second = 1;
	}
	for (auto &x : ans) cout << x << " ";
	return 0;
}
