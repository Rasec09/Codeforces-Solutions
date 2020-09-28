#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

vector<int> div(int n) {
	vector<int> d;
	for (int i = 1; i *i <= n; i++) {
		if (n % i == 0) {
			d.push_back(i);
			if (i != n / i)
				d.push_back(n / i);
		}
	}
	sort(d.begin(), d.end());
	return d;
}

vector<int> build(int y, int d, int n) {
	vector<int> v;
	v.push_back(y);
	int aux = y;
	while (v.size() < n and aux - d > 0) {
		v.push_back(aux - d);
		aux -= d;
	}
	while (v.size() < n) {
		v.push_back(y + d);
		y += d;
	}
	sort(v.begin(), v.end());
	return v;
}

int main() {
	optimizar_io
	int tc, n, x, y;

	cin >> tc;
	while (tc--) {
		cin >> n >> x >> y;
		if (n == 2) {
			cout << x << " " << y << "\n";
			continue;
		}
		vector<int> d = div(y - x);
		vector<int> ans;
		for (int i = 0; i < d.size(); i++) {
			vector<int> tmp = build(y, d[i], n);
			if (binary_search(tmp.begin(), tmp.end(), x)) {
				if (ans.empty())
					ans = tmp;
				else {
					if (tmp.back() < ans.back())
						ans = tmp;
				}
			}
		}
		for (int a : ans)
			cout << a << " ";
		cout << "\n";
	}
	return 0;
}
