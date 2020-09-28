#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, p, f, s, w, cntS, cntW;

	cin >> tc;
	while (tc--) {
		cin >> p >> f >> cntS >> cntW >> s >> w;
		if (s > w) {
			swap(s, w);
			swap(cntS, cntW);
		}
		int limit = min(p / s, cntS), ans = 0;
		for (int i = 0; i <= limit; i++) {
			int sA = i;
			int wA = min((p - sA * s) / w, cntW);
			int sB = min(cntS - sA, f / s);
			int wB = min(cntW - wA, (f - sB * s) / w);
			ans = max(ans, sA + wA + sB + wB);
		}
		cout << ans << "\n";
	}
	return 0;
}
