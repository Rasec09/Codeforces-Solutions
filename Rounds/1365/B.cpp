#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef pair<int,int> ii;
 
bool solve(vector<ii> &a, int n) {
	bool sorted = true;
    for (int i = 0; i + 1 < n; i++) {
        if (a[i].first > a[i + 1].first) {
            sorted = false;
            break;
        }
    }
    if (sorted) return true;
    bool ones = false, zeros = false;
    for (int i = 0; i < n; i++) {
        if (a[i].second == 1) ones = true;
        else zeros = true;
    }
    return (ones && zeros);
}

int main() {
	optimizar_io
	int tc, n; 
	vector<ii> arr;
 
	cin >> tc;
	while (tc--) {
		cin >> n;
		arr.assign(n, ii(0, 0));
		for (int i = 0; i < n; i++) cin >> arr[i].first;
		for (int i = 0; i < n; i++) cin >> arr[i].second;	
		cout << (solve(arr, n) ? "Yes\n" : "No\n");
	}
	return 0;
}
