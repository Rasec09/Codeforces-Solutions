#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

struct climber {
	int s, a;
	bool operator<(const climber &other) const {
		if (max(s, a) == max(other.s, other.a))
			return s < other.s;
		return max(s, a) < max(other.s, other.a);
	}
};

int main() {
	optimizar_io
	int n, d;
	vector<climber> alp;

	cin >> n >> d;
	alp.assign(n, {0,0});
	for (int i = 0; i < n; i++) cin >> alp[i].s >> alp[i].a;
	sort(alp.begin(), alp.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (alp[i].s >= d) {
			d = max(d, alp[i].a);
			ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
