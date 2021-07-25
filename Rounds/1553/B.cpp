#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

bool possible(string &s, string &t) {
	int n = s.size(), m = t.size();
	for (int idx = 0; idx < n; idx++) {
		for (int rightMv = 0; rightMv < m; rightMv++) {
			int leftMv = m - rightMv;
			string t1 = "";
			int i = idx;
			for (int j = 0; i < n and j < rightMv; j++) {
				t1.push_back(s[i]);
				i++;
			}
			for (int j = 0; i >= 0 and j < leftMv; j++) {
				t1.push_back(s[i]);
				i--;
			}
			if (t == t1) return true;
		}
	}
	return false;
}

int main() {
	optimizar_io
	int q;
	string s, t;

	cin >> q;
	while (q--) {
		cin >> s >> t;
		cout << (possible(s, t) ? "YES" : "NO") << "\n";
	}
	return 0;
}
/* stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?), even odd
	* DON'T GET STUCK ON ONE APPROACH
*/
/*
1
zcefropajazfquepabdbyhntfsnlojivylykqxyfpymxzdynpxksnwxmjcasssumryrxyvjrulnzqjoyohppmeylkqafrcvtqocopsqvagcvhokbbhjrugllqdijyuxfcsghzesjsigwqmypvaglhrskhfskspsscgewpbagwnduopkshplehxooimugnwqwyxrxmpofbsrchsgncciadliqfphoyjbvqyupikpokkzkukklqgfsnucwox
jcasssumryrxyvjrulnzqjoyohppmeylkqafrcvtqocopsqvagcvhokbbhjrugllqdijyuxfcsghzesjsigwqmypvaglhrskhfskspsscgewpbagwnduopkshplehxooimugnwqwyxrxmpofbsrchsgncciadliqfphohpfqildaiccngshcrsbfopmxrxywq
*/
