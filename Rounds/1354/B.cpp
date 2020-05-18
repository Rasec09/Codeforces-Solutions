#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
int main() {
    optimizar_io
    int tc;
    string s;

    cin >> tc;
    while (tc--) {
    	cin >> s;
    	vector<int> cnt(4);
    	cnt[s[0] - '0'] = 1;
    	int ans = numeric_limits<int>::max(), l = 0, r = 0;
    	while (r < s.size()) {
    		if (cnt[1] and cnt[2] and cnt[3]) {
    			ans = min(ans, r - l + 1);
    			cnt[s[l] - '0']--;
    			l++;
    		}
    		else {
    			if (r + 1 < s.size())
    				cnt[s[r + 1] - '0']++;
    			r++;
    		}
    	}
    	if (ans == numeric_limits<int>::max())
    		cout << "0\n";
    	else
    		cout << ans << "\n";
    }
    return 0;
}
