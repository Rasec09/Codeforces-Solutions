#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
	optimizar_io
	int t, n, a[55];
	
    cin >> t;
	while(t--) {
		cin >> n;
        int par = 0, impar = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] & 1)
                impar++;
            else
                par++;
        }
        if (par % 2 == 0 and impar % 2 == 0) {
            cout << "YES\n";
            continue;
        }
        bool possible = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (abs(a[i] - a[j]) == 1) {
                    possible = true;
                    break;
                }
            }
        }
        cout << (possible ? "YES\n" : "NO\n");
	}
}
