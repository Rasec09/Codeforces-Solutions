#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
    optimizar_io
    int n, a[200010], b[200010];
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> b[i];
    a[0] = b[0];
    a[1] = b[0] + b[1]; 
    int x = max(0, a[0]);
    for (int i = 2; i < n; i++) {
        x = max(x, a[i - 1]);
        a[i] = b[i] + x;
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
    return 0;
}
