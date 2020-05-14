#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
    optimizar_io
    int tc, n, p[200010];
    map<int,int> idx;
 
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
        	cin >> p[i];
        	idx[p[i]] = i;
        }
        vector<int> used(n);
        int next = 1;
        bool possible = true;
        while (next <= n) {
        	//cout << next << "\n";
	        used[idx[next]] = true;
	        for (int i = idx[next]; i + 1 < n and !used[i + 1] ; i++) {
	            used[i + 1] = true;
	            next = p[i + 1];
	            if (p[i] + 1 != p[i + 1]) {
	                possible = false;
	                break;
	            }
	        }
	        if (!possible) break;
	        next = next + 1;
        }
        cout << (possible ? "Yes\n" : "No\n");
    }
    return 0;
}
