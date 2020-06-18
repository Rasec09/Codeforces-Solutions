#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int n, a[100010];
 
	cin >> n;
	set<int> used;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		used.insert(a[i]);
	}
	vector<int> ans(n, -1);
	for (int i = 1; i < n; i++) {
		if (a[i] != a[i - 1])
			ans[i] = a[i - 1];
	}
	int mex = 0;
	for (int i = 0; i < n; i++) {
		if (ans[i] == -1) {
			while (used.count(mex))
				mex++;
			ans[i] = mex;
			used.insert(mex);
		}
	}
	for (auto _a : ans)
		cout << _a << " ";
	cout << "\n";
	return 0;
}
