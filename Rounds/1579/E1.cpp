#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
 
int main() {
	optimizar_io
	int tc, n;
	array<int,200000> p;

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> p[i];
		deque<int> dq;
		for (int i = 0; i < n; i++) {
			if (dq.empty()) {
				dq.push_back(p[i]);
			}
			else {
				if (p[i] < dq.front())
					dq.push_front(p[i]);
				else
					dq.push_back(p[i]);
			}
		}
		for (int i = 0; i < n; i++) cout << dq[i] << " ";
		cout << "\n";
	}
	return 0;
}
