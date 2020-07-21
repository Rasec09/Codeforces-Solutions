#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int dp(string &s, int l, int r, char c) {
    if (l < r) {
        int m = l + (r - l) / 2;
        int cnt1 = 0;
        for (int i = l; i <= m; i++) {
            if (s[i] != c)
                cnt1++;
        }
        int cnt2 = 0;
        for (int i = m + 1; i <= r; i++) {
            if (s[i] != c)
                cnt2++;
        }
        return min(dp(s, m + 1, r, c + 1) + cnt1, dp(s, l, m, c + 1) + cnt2);
    }
    return (s[l] != c);
}

int main() {
    optimizar_io
    int tc, n;
    string s;
    
    cin >> tc;
    while (tc--) {
        cin >> n >> s;
        cout << dp(s, 0, n - 1, 'a') << "\n";
    }
    return 0;
}
