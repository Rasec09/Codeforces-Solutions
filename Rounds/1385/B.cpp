#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
    optimizar_io
    int tc, n, a[105];
    
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 0; i < 2 * n; i++) cin >> a[i];
        set<int> prev;
        for (int i = 0; i < 2 * n; i++) {
            if (!prev.count(a[i]))
                cout << a[i] << " ";
            prev.insert(a[i]);
        }
        cout << "\n";
    }
    return 0;
}
