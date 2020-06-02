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
 		int n = s.size();
 		int ones = 0, zeros = 0;
 		for (int i = 0; i < n; i++) {
 			if (s[i] == '1')
 				ones++;
 			else
 				zeros++;
 		}
 		int currOnes = 0, currZeros = 0, ans = 1e9;
 		for (int i = 0; i < n; i++) {
 			if (s[i] == '1')
 				currOnes++;
 			else
 				currZeros++;
 			ans = min({ans, currZeros + ones - currOnes, currOnes + zeros - currZeros});
 		}
 		cout << ans << "\n";
 	}
    return 0;
}
