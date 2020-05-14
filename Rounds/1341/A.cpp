#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
int main() {
    optimizar_io
    int tc, n, a, b, c, d;
 
    cin >> tc;
    while (tc--) {
    	cin >> n >> a >> b >> c >> d;
    	int low = n * (a - b);
        int hig = n * (a + b);
        if (low > c + d or hig < c - d)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    return 0;
}
