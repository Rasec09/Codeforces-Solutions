#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
    optimizar_io
    int tc, n;
    string matrix[55];

    cin >> tc;
    while (tc--) {
    	cin >> n;
        for (int i = 0; i < n; i++) cin >> matrix[i];
        bool possible = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    if (i == n - 1 or j == n - 1) {
                        continue;
                    }
                    if (i + 1 < n and matrix[i + 1][j] == '1') {
                        continue;
                    }
                    if (j + 1 < n and matrix[i][j + 1] == '1') {
                        continue;
                    }
                    possible = false;
                    //cout << i << " " << j << "\n";
                    break;
                }
            }
        }
        cout << (possible ? "YES\n" : "NO\n");
    }
    return 0;
}
