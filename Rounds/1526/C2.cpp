#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long int ll;

int main() {
	optimizar_io
    int n, a[200010];

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	ll health = 0;
	priority_queue<int,vector<int>,greater<int>> pq;
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			pq.push(a[i]);
			health += a[i];
		}
		else {
			if (health + a[i] >= 0) {
				pq.push(a[i]);
				health += a[i];
			}
			else {
				if (!pq.empty() and pq.top() < a[i]) {
					health -= pq.top(); 
					pq.pop();
					health += a[i];
					pq.push(a[i]);
				}
			}
		}
	}
	cout << pq.size() << "\n";
	return 0;
}
