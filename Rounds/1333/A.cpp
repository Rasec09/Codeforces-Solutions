#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
    optimizar_io
    int tc, n, m, ans[105][105];

    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i + j) % 2 == 0)
                    ans[i][j] = 1;
                else
                    ans[i][j] = 0;
            }
        }
        if ((n * m) % 2 == 0) {
            ans[0][1] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ans[i][j])
                    cout << "B";
                else
                    cout << "W";
            }
            cout << "\n";
        }
    }
    return 0;
}
