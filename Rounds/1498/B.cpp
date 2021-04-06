#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
    int tc, n, w, a[100010];

	cin >> tc;
	while (tc--) {
		cin >> n >> w;
		for (int i = 0; i < n; i++) cin >> a[i];
		map<int,int> freq;
		for (int i = 0; i < n; i++) freq[a[i]]++;
		int ans = 0;
		while (freq.size()) {
			int largest = freq.rbegin()->first;
			freq[largest]--;
			if (freq[largest] == 0)
				freq.erase(largest);
			int currSize = w - largest;
			while (currSize > 0) {
				auto it = freq.upper_bound(currSize);
				if (it == freq.begin())
					break;
				it--;
				int tmp = it->first;
				freq[tmp]--;
				if (freq[tmp] == 0)
					freq.erase(tmp);
				currSize -= tmp;
			}
			ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}
