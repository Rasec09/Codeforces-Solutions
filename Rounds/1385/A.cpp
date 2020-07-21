#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
    optimizar_io
    int tc, x, y, z;
    
    cin >> tc;
    while (tc--) {
        cin >> x >> y >> z;
        map<int,int> freq;
        freq[x]++;
        freq[y]++;
        freq[z]++;
        if (freq.rbegin() -> second < 2) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
            cout << max({x, y, z}) << " " << min({x, y, z}) << " " << min({x, y, z}) << "\n"; 
        }
    }
    return 0;
}
