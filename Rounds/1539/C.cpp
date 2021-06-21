#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
	
typedef long long int ll;
	
int main() {
	optimizar_io
	ll n, k, x, a[200010];
	
	cin >> n >> k >> x;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	priority_queue<ll,vector<ll>,greater<ll>> pq;
	for (int i = 0; i + 1 < n; i++) {
		if (a[i + 1] - a[i] > x) {
			ll d = a[i + 1] - a[i] - 1;
			pq.push(d / x);
		}
	}
	while (k > 0 and !pq.empty()) {
		ll need = pq.top();
		if (k >= need)
			k -= need;
		else
			break;
		pq.pop();
	}
	cout << pq.size() + 1 << "\n";
	return 0;
}
