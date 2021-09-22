#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0); 

typedef long long int ll;

int n, m; 
ll x, y;
array<ll,200000> hero;
vector<pair<ll,ll>> dragon;

ll solve1(int idx, ll total) {
	auto it = upper_bound(hero.begin(), hero.begin() + n, dragon[idx].first);
	ll killer = 0;
	if (it == hero.begin() + n) {
		killer = hero[n - 1];
	}
	else {
		if (it != hero.begin())
			it--;
		killer = *it;
	}
	ll coins = 0;
	if (dragon[idx].first > killer)
		coins += dragon[idx].first - killer;
	
	ll rem = total - killer;
	if (dragon[idx].second > rem)
		coins += dragon[idx].second - rem;

	return coins;
}

ll solve2(int idx, ll total) {
	auto it = upper_bound(hero.begin(), hero.begin() + n, dragon[idx].first);
	ll killer = 0;
	if (it == hero.begin() + n) {
		killer = hero[n - 1];
	}
	else {
		killer = *it;
	}
	
	ll coins = 0;
	if (dragon[idx].first > killer)
		coins += dragon[idx].first - killer;
	
	ll rem = total - killer;
	if (dragon[idx].second > rem)
		coins += dragon[idx].second - rem;

	return coins;
}

int main() {
	optimizar_io
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> hero[i];
	cin >> m;
	for (int j = 0; j < m; j++) {
		cin >> x >> y;
		dragon.emplace_back(x, y);
	}
	sort(hero.begin(), hero.begin() + n);
	ll total = 0;
	for (int i = 0; i < n; i++) total += hero[i];
	for (int i = 0; i < m; i++) {
		cout << min(solve1(i, total), solve2(i, total)) << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
