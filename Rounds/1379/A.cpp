#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int count(string &s, string &t, int n, int m) {
    int cnt = 0;
    for (int i = 0; i + m <= n; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (s[i + j] != t[j])
                break;
        }
        if (j == m) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    optimizar_io
    int tc, n, m = 7;
    string s, t = "abacaba";

    cin >> tc;
    while (tc--) {
        cin >> n >> s;
        bool ans = false;
        for (int i = 0; i + m <= n; i++) {
            string tmp = s.substr(i, m);
            for (int j = 0; j < m; j++) {
                if (s[i + j] == '?') {
                    s[i + j] = t[j];
                }
            }
            int cnt = count(s, t, n, m);
            if (cnt == 1) {
                ans = true;
                break;
            }
            else {
                for (int j = 0; j < m; j++)
                    s[i + j] = tmp[j];
            }
        }
        if (ans) {
            for (int i = 0; i < n; i++) {
                if (s[i] == '?')
                    s[i] = 'z';
            }
            cout << "Yes\n" << s << "\n";
        }
        else {
            cout << "No\n";
        }
    }
    return 0;
}
