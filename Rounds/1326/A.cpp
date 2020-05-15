#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
    optimizar_io
    int t, n;
    
    cin >> t;
    while (t--) {
        cin >> n;
        string s = "";
        if (n == 1) {
            cout << "-1\n";
        }
        else {
            s.push_back('2');
            for (int i = 0; i + 1 < n; i++) 
                s.push_back('3');
            cout << s << "\n";
        }
    }
    return 0;
}
