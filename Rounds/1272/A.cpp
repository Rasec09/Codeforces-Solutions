#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
    int tc, a, b, c;

	cin >> tc;
	while (tc--) {
		cin >> a >> b >> c;
		vector<int> x;
		x.push_back(a);
		x.push_back(b);
		x.push_back(c);
		sort(x.begin(), x.end());
		int minEle = x[0];
		int maxEle = x[2];
		int midEle = x[1];
		// cout << minEle << " " << midEle << " " << maxEle << "\n";
		if (minEle == midEle and midEle < maxEle) {
			minEle++;
			midEle++;
			if (maxEle > midEle)
				maxEle--;
			int ans = abs(minEle  - maxEle) + abs(minEle - midEle) + abs(maxEle - midEle);
			cout << ans << "\n";
			continue;
		}
		if (midEle == maxEle and midEle > minEle) {
			maxEle--;
			midEle--;
			if (minEle < midEle)
				minEle++;
			int ans = abs(minEle  - maxEle) + abs(minEle - midEle) + abs(maxEle - midEle);
			cout << ans << "\n";
			continue;
		}
		if (minEle + 1 <= midEle)
			minEle++;
		if (maxEle - 1 >= midEle)
			maxEle--;
		// cout << minEle << " " << midEle << " " << maxEle << "\n";
		int ans = abs(minEle  - maxEle) + abs(minEle - midEle) + abs(maxEle - midEle);
		cout << ans << "\n";
	}
	return 0;
}
