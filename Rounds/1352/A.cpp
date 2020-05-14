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
 		int cnt = 0;
 		for (int i = 0; i < s.size(); i++) {
 			if (s[i] != '0')
 				cnt++;
 		}
 		int zeros = int(s.size()) - 1;
 		cout << cnt << "\n";
 		for (int i = 0; i < s.size(); i++) {
 			if (s[i] != '0') {
 				cout << s[i];
 				for (int j = 0; j < zeros; j++)
 					cout << '0';
 				cout << " ";
 			}
 			zeros--;
 		}
 		cout << "\n";
 	}
    return 0;
}
