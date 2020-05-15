#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
    optimizar_io
    int t, a, b;

    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (a % b == 0) {
            cout << "0\n";
        }
        else {
            int d = a / b;
            int next = b * (d + 1);
            cout << next - a << "\n";
        }
    }
    return 0;
}
