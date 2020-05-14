#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
    optimizar_io 
    int tc, a[9][9];
    string s[9];

    cin >> tc;
    while (tc--) {
        for (int i = 0; i < 9; i++) cin >> s[i];
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                a[i][j] = s[i][j] - '0';
        a[0][0] = a[1][0];
        a[1][4] = a[0][4];
        a[2][8] = a[1][8];

        a[3][1] = a[4][1]; 
        a[4][5] = a[5][5];
        a[5][6] = a[4][6];

        a[6][2] = a[7][2];
        a[7][3] = a[8][3];
        a[8][7] = a[8][8];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << a[i][j];
            cout << "\n";
        }
    }
    return 0;
}
