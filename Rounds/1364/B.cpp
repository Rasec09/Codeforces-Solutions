#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int tc, n, a[200010];
 
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<int> ans;
		ans.push_back(a[0]);
        for (int i = 1; i + 1 < n; i++) {
            if (a[i] > a[i - 1] and a[i] > a[i + 1])
                ans.push_back(a[i]);
            if (a[i] < a[i - 1] and a[i] < a[i + 1])
                ans.push_back(a[i]);
        }
        ans.push_back(a[n - 1]);
        cout << ans.size() << "\n";
		for (auto a : ans)
			cout << a << " ";
		cout << "\n";
	}
	return 0;
}
