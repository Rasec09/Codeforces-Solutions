#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
    optimizar_io
    
    int tc, n;
    vector<int> s;
        
    cin >> tc;
    while (tc--) {
        cin >> n;
        s.assign(n, 0);
        for (int i = 0; i < n; i++) cin >> s[i];
        sort(s.begin(), s.end());
        //for (int i = 0; i < n; i++) cout << s[i] << " ";
        //cout << "\n";
        set<int> diff;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++)
                diff.insert(s[i] ^ s[j]);
        }
        bool ok = false;
        for (auto k : diff) {
            vector<int> t(n);
            for (int i = 0; i < n; i++)
                t[i] = s[i] ^ k;
            sort(t.begin(), t.end());
            if (t == s) {
                cout << k << "\n";
                ok = true;
                break;
            }
        }
        if (!ok) cout << "-1\n";
    }
    return 0;
}
