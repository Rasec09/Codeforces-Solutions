#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

bool esPermutacion(map<int,int> &p, int size) {
    auto it = p.rbegin();
    int maxNum = it -> first;
    return (p.size() == size and maxNum == size);
}

int main() {
    optimizar_io
    int t, n, a[200010];
    
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        map<int,int> left, right;
        for (int i = 0; i < n; i++)
            right[a[i]]++;
        vector<int> ans;
        for (int i = 0; i + 1 < n; i++) {
            left[a[i]]++;
            if (right.count(a[i])) {
                right[a[i]]--;
                if (right[a[i]] == 0)
                    right.erase(a[i]);
            }
            //esPermutacion(left, i + 1);
            //esPermutacion(right, n-i+1);
            if (esPermutacion(left, i + 1) and esPermutacion(right, n - (i + 1)))
                ans.push_back(i + 1);
        }
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " " << n - ans[i] << "\n";
    }
    return 0;
}
