#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
    optimizar_io 
    int tc, n, a[200010];
    map<int,int> freq;

    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }
        int mx = 0;
        for (auto f : freq) {
            mx = max(mx, f.second);
        }
        n = freq.size();
        cout << max(min(n - 1, mx), min(n, mx - 1)) << "\n";
        freq.clear();
    }
    return 0;
}
