#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
    optimizar_io
    int tc, n, a[100005], b[100005];

    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int j = 0; j < n; j++) cin >> b[j];
        if (a[0] != b[0]) {
            cout << "NO\n";
            continue;
        }
        set<int> mySet;
        mySet.insert(a[0]);
        bool possible = true;
        for (int i = 1; i < n; i++) {
            if (b[i] > a[i]) {
                if (!mySet.count(1)) {
                    possible = false;
                    break;
                }
            }
            else if (b[i] < a[i]) {
                if (!mySet.count(-1)) {
                    possible = false;
                    break;
                }
            }
            mySet.insert(a[i]);
        }
        cout << (possible ? "YES" : "NO") << "\n";
        mySet.clear();
    }
    return 0;
}
