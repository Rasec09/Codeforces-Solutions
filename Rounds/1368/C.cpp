#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef pair<int,int> ii;

int main() {
	optimizar_io
	int n, x = 0, y = 0;
	set<ii> grises;

	cin >> n;
	for (int i = 0; i < n; i++) {
		grises.insert(ii(x, y));
		grises.insert(ii(x + 1, y));
		grises.insert(ii(x - 1, y));
		grises.insert(ii(x, y + 1));
		grises.insert(ii(x, y - 1));
		grises.insert(ii(x - 1, y + 1));
		grises.insert(ii(x + 1, y - 1));
		x++;
		y--;
	}
	cout << grises.size() << "\n";
	for (auto g : grises) {
		cout << g.first << " " << g.second << "\n";
	}
	return 0;
}
