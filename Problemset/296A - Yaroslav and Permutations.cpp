#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
    optimizar_io
 	int n, x;
 	map<int,int> cnt;

 	cin >> n;
 	for (int i = 0; i < n; i++) {
 		cin >> x;
 		cnt[x]++;
 	}
 	int mx = -1;
 	for (auto c : cnt) {
 		mx = max(mx, c.second);
 	}
 	cout << (mx > (n + 1) / 2 ? "NO\n" : "YES\n");
    return 0;
}
