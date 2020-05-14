#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int greatest_divisor(int n) {
	int d = 1;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			d = n / i;
			break;
		}
	}
	return d;
}

int main() {
    optimizar_io 	
 	int n;
 	vector<int> ans;

 	cin >> n;
 	for (int i = 2; i <= n; i++) {
 		ans.push_back(greatest_divisor(i));
 	}
 	sort(ans.begin(), ans.end());
 	for (auto x : ans)
 		cout << x << " ";
 	cout << "\n";
    return 0;
}
