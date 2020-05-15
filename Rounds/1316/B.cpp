#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
int main() {
	optimizar_io
	int t, n;
	string s;
	vector<pair<string,int>> palabras;
 
	cin >> t;
	while (t--) {
		cin >> n >> s;
		palabras.push_back(make_pair(s, 1));
		for (int i = 1; i < n; i++) {
			string s1 = s.substr(i, n - i + 1);
			string s2 = s.substr(0, i);
			if (n % 2 != i % 2) {
				reverse(s2.begin(), s2.end());
			}
			palabras.push_back(make_pair(s1 + s2, i + 1));
		}
		sort(palabras.begin(), palabras.end());
		cout << palabras[0].first << "\n" << palabras[0].second << "\n";
		palabras.clear();
	}
	return 0;
}
