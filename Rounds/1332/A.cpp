#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
    optimizar_io
    int left, right, down, up, x, y, x1, x2, y1, y2, t;

    cin >> t;
    while (t--) {
        cin >> left >> right >> down >> up;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        if (x == x1 and x == x2) {
            if (left >= 1 or right >= 1) {
                cout << "No\n";
                continue;
            }
        }
        if (y == y1 and y == y2) {
            if (up >= 1 or down >= 1) {
                cout << "No\n";
                continue;
            }
        }
        x -= left;
        x += right;
        y -= down;
        y += up;
        if (x < x1 or x > x2 or y < y1 or y > y2)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    return 0;
}
