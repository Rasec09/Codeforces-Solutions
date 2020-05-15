#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
    optimizar_io
    int t, n, k, x;
    vector<priority_queue<int,vector<int>,greater<int>>> g;
    set<int> numbers;

    cin >> t;
    while (t--) {
        cin >> n;
        g.assign(n + 1, priority_queue<int,vector<int>,greater<int>>());
        for (int i = 1; i <= n; i++) {
            cin >> k;
            for (int j = 0; j < k; j++) {
                cin >> x;
                g[i].push(x);
            }
            numbers.insert(i);
        }
        vector<int> matched(n + 1);
        for (int i = 1; i <= n; i++) {
            while (!g[i].empty()) {
                x = g[i].top();
                g[i].pop();
                if (numbers.count(x)) {
                    numbers.erase(x);
                    matched[i] = true;
                    break;
                }
            }
        }
        if (numbers.empty()) {
            cout << "OPTIMAL\n";
        }
        else {
            cout << "IMPROVE\n";
            for (int i = 1; i <= n; i++) {
                if (!matched[i]) {
                    cout << i << " " << *numbers.begin() << "\n";
                    break;
                }
            }
        }
        g.clear();
        numbers.clear();
    }
    return 0;
}
