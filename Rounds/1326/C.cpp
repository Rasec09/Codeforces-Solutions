#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;
typedef pair<ll,int> ii;

const ll mod = 998244353;

int main() {
    optimizar_io
    int n, k, p[200010];
    priority_queue<ii> pq;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        pq.push(ii(p[i], i));
    }
    vector<int> pos;
    ll maxVal = 0;
    while (k--) {
        ii tope = pq.top();
        pq.pop();
        maxVal += tope.first;
        pos.push_back(tope.second);
    }
    sort(pos.begin(), pos.end());
    ll ans = 1;
    for (int i = 1; i < pos.size(); i++) {
        ll diff = pos[i] - pos[i - 1];
        ans = (ans % mod) * (diff % mod);
        ans %= mod;
    }
    cout << maxVal << " " << ans << "\n";
    return 0;
}
