#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
    optimizar_io
    int tc, n, a[100010];
    map<int,int> freq;

    cin >> tc;
    while (tc--) {
    	cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }
        int ans = 1, sum = 0;
        for (auto f : freq) {
            sum += f.second;
            if (sum >= f.first)
                ans = sum + 1;
        }
        cout << ans << "\n";
        freq.clear();
    }
    return 0;
}
