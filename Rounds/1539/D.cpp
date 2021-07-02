#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;

struct item {
	ll dis, req;
	bool operator<(const item &i) const {
		return dis < i.dis;
	}
};

int main() {
	optimizar_io
	int n;
	ll a, b;
	vector<item> ii;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		ii.push_back({b, a});
	}
	sort(ii.begin(), ii.end());
	ll ans = 0, buy = 0;
	int i = 0, j = n - 1;
	while (i <= j) {
		if (buy >= ii[i].dis) { // comprar con descuento
			buy += ii[i].req;
			ans += ii[i].req;
			ii[i].req = 0;
			i++;						
		}
		else { // comprar sin descuento
			ll mn = min(ii[i].dis - buy, ii[j].req);
			buy += mn;
			ans += 2 * mn;
			ii[j].req -= mn;
			if (ii[j].req == 0)
				j--;
		}
	}
	cout << ans << "\n";
	return 0;
}
