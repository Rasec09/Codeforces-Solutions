#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
#define x first
#define y second

typedef pair<int,int> ii;

int main() {
    optimizar_io
    int n, m, k, sx, sy;
    vector<ii> ini, fin;

    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> sx >> sy;
        ini.push_back(ii(sx, sy));
    }
    for (int i = 0; i < k; i++) {
        cin >> sx >> sy;
        fin.push_back(ii(sx, sy));
    }
    sort(fin.begin(), fin.end());
    string ans;
    for (int i = 0; i < n; i++)
        ans.push_back('U');
    for (int i = 0; i < m; i++)
        ans.push_back('L');

    sx = sy = 1;
    for (int i = 0; i < k; i++) {
        while (sx != fin[i].x or sy != fin[i].y) {
            if (sx < fin[i].x) {
                sx += 1;
                sx = min(sx, n);
                ans.push_back('D');
            }
            else if (sx > fin[i].x) {
                sx -= 1;
                sx = max(sx, 1);
                ans.push_back('U');
            }
            else if (sy < fin[i].y) {
                sy += 1;
                sy = min(sy, m);
                ans.push_back('R');
            }
            else if (sy > fin[i].y) {
                sy -= 1;
                sy = max(sy, 1);
                ans.push_back('L');
            }
        }
    }
    cout << ans.size() << "\n" << ans << "\n";
    return 0;
}
