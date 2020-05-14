#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
int main() {
    optimizar_io 
    int tc, n, a, b;
 
    cin >> tc;
    while (tc--) {
        cin >> n >> a >> b;
        string s;
        for (int i = 0; i < b; i++) {
        	s.push_back('a' + i);
        }
        for (int i = 0; i < n; i++) {
        	cout << s[i % b];
        }
        cout << "\n";
    }
    return 0;
}
