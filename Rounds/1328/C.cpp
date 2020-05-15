#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
    optimizar_io
    int t, n;
    string x, a, b;

    cin >> t;
    while (t--) {
        cin >> n >> x;
        for (int i = 0; i < n; i++) {
            if (x[i] == '0') {
                a.push_back('0');
                b.push_back('0');
            }
            else if (x[i] == '1') {
                a.push_back('1');
                b.push_back('0');   
            }
            else {
                a.push_back('0');
                b.push_back('2');
            }
        }
        cout << a << "\n" << b << "\n";
        a.clear();
        b.clear();
    }
    return 0;
}
