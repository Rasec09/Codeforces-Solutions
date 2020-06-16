#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
    optimizar_io
 	string x;
 	vector<string> s; 

 	cin >> x;
 	for (int i = 0; i < x.size(); i++) {
 		for (int j = i + 1; j < x.size(); j++) {
 			string tmp = x;
 			swap(tmp[i], tmp[j]);
 			s.push_back(tmp);
 		}
 	}
 	sort(s.begin(), s.end(), greater<string>());
 	for (int i = 0; i < s.size(); i++) {
 		if (s[i] < x and s[i][0] != '0') {
 			cout << s[i] << "\n";
 			return 0;
 		}
 	}
 	cout << "-1\n";
    return 0;
}
