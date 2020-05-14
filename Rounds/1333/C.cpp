#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
    optimizar_io
    int n, a[200010];
    map<ll,int> mp;

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    mp[0] = 0;
    ll sum = 0, ans = 0;
    int pos = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        if (mp.count(sum)) {
            pos = max(pos, mp[sum] + 1);
        }
        mp[sum] = i;
        ans += i - pos;
    }
    cout << ans << "\n";
    return 0;
}
