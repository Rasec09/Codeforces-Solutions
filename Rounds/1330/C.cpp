#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
    optimizar_io
    ll n, m, l[100010];

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> l[i];
        if (l[i] + i - 1 > n) {
            cout << "-1\n";
            return 0;
        }
    }
    for (int i = m - 1; i >= 0; i--) {
        l[i] += l[i + 1];
    }
    if (l[0] < n) return cout << "-1\n", 0;
    for (int i = 1; i <= m; i++) {
        cout << max(1LL * i, n - l[i] + 1) << " ";
    }
    cout << "\n";
    return 0;
}
