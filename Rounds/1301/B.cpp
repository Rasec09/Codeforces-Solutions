#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
    optimizar_io

  int t, n, a[100010];

  cin >> t;
  while (t--) {
        cin >> n;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] != -1)
                cnt++;
        }
        int minVal = 1e9, maxVal = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] == -1) {
                if (i - 1 >= 0 and a[i - 1] != -1) {
                    minVal = min(minVal, a[i - 1]);
                    maxVal = max(maxVal, a[i - 1]);
                }
                if (i + 1 < n and a[i + 1] != -1) {
                    minVal = min(minVal, a[i + 1]);
                    maxVal = max(maxVal, a[i + 1]);    
                }
            }
        }
        if (cnt == 0) {
            cout << "0 0\n";
            continue;
        }
        int k = (minVal + maxVal) / 2, m = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == -1)
                a[i] = k;
        }
        for (int i = 0; i + 1 < n; i++)
            m = max(m, abs(a[i] - a[i + 1]));
        cout << m << " " << k << "\n";
    }
    return 0;
}
