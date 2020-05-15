#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int lowerbound(vector<ll> &arr, ll x) {
    int left = 0, right = arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (x <= arr[mid])
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int main() {
    optimizar_io
    int t, n, k;
    vector<ll> tri;

    tri.push_back(1);
    for (ll i = 2; ;i++) {
        tri.push_back(i * (i + 1) / 2);
        if (tri[i - 1] >= 2000000000)
            break;
    }
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int pos = lowerbound(tri, k);
        string ans;
        for (int i = 0; i <= pos; i++)
            ans.push_back('a');
        int idx = ans.size();
        ans.push_back('b');
        while (ans.size() < n)
            ans.push_back('a');
        if (tri[pos] > k) pos--;
        k -= tri[pos];
        if (k == 0) {
            ans[idx - 1] = 'b';
        }
        else
            ans[k - 1] = 'b';
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
    return 0;
}
