#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int n, a[100010], memo[100010];

vector<int> divisores(int n) {
    vector<int> d;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            d.push_back(i);
            if (i != n / i)
                d.push_back(n / i);
        }
    }
    return d;
}

int dp(int i) {
    if (i == 1) return 1;
    if (memo[i] != -1) return memo[i];
    vector<int> d = divisores(i);
    int ans = 1;
    for (int j = 0; j < d.size(); j++) {
        if (a[i] > a[d[j]])
            ans = max(ans, 1 + dp(d[j]));
    } 
    return memo[i] = ans;
}

int main() {
    optimizar_io
    int tc;

    cin >> tc;
    while (tc--) {
    	cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        memset(memo, -1, sizeof(memo));
        int ans = 1;
        for (int i = 1; i <= n; i++)
            ans = max(ans, dp(i));
        cout << ans << "\n";
    }
    return 0;
}
