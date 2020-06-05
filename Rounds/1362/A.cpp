#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
    optimizar_io
    
    int tc;
    ll a, b;
        
    cin >> tc;
    while (tc--) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        int cnt = 0;
        while (a < b) {
            cnt++;
            if (a * 8 <= b)
                a *= 8;
            else if (a * 4 <= b)
                a *= 4;
            else
                a *= 2;
        }
        if (a != b) {
            cout << "-1\n";
        }
        else {
            cout << cnt << "\n";
        }
    }
    return 0;
}
