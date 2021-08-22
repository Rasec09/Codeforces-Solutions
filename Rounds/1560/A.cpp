#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
 
int main() {
	optimizar_io
	int tc, n;
	vector<int> nums;

	for (int i = 1; nums.size() < 1000; i++) {
		if (i % 3 != 0 and i % 10 != 3)
			nums.push_back(i);
	}
	cin >> tc;
	while (tc--) {
		cin >> n;
		cout << nums[n - 1] << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
