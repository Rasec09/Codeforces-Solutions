#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;

string intToStr(ll x) {
	stringstream ss;
	ss << x;
	string str = ss.str();
	return str;
}

int solve(string &num, string &str) {
	int i = 0, j = 0, taken = 0;
	while (i < num.size() and j < str.size()) {
		if (num[i] == str[j]) {
			j++;
			taken++;
		}
		i++;
	}
	int ans = int(num.size()) + int(str.size()) - 2 * taken;
	return ans;
}

int main() {
	optimizar_io
	int tc; 
	ll pot = 1;
	string num;
	vector<string> powerOfTwo;

	vector<string> v;
	while (pot <= 1e18) {
		string s = intToStr(pot);
		powerOfTwo.push_back(s);
		pot *= 2;
	}
	cin >> tc;
	while (tc--) {
		cin >> num;
		int ans = int(num.size()) + 1;
		for (int i = 0; i < powerOfTwo.size(); i++) {
			ans = min(ans, solve(num, powerOfTwo[i]));
		}
		cout << ans << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
