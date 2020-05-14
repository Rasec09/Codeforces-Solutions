#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
int main() {
    optimizar_io
 	int tc, n, k;

 	cin >> tc;
 	while (tc--) {
 		cin >> n >> k;
 		if (k > n) {
 			cout << "NO\n";
 			continue;
 		}
 		if (k == 1) {
 			cout << "YES\n" << n << "\n";
 			continue;
 		}
 		if (n & 1) {
 			if (k & 1) {
 				int sum = 0;
	 			for (int i = 0; i + 1 < k; i++) {
	 				sum += 1;
	 				//cout << 1 << " ";
	 			}
	 			if ((n - sum) & 1) {
	 				cout << "YES\n";
	 				for (int i = 0; i + 1 < k; i++)
	 					cout << 1 << " ";
	 				cout << n - sum << "\n";
	 			}
	 			else {
	 				cout << "NO\n";
	 			}

 			}
 			else 
 				cout << "NO\n";
 		}
 		else {
 			if (k <= n / 2) {
 				cout << "YES\n";
 				int sum = 0;
 				for (int i = 0; i + 1 < k; i++) {
 					sum += 2;
 					cout << 2 << " ";
 				}
 				cout << n - sum << "\n";
 			}
 			else {
 				if (n % 2 == k % 2) {
 					cout << "YES\n";
 					int sum = 0;
	 				for (int i = 0; i + 1 < k; i++) {
	 					sum += 1;
	 					cout << 1 << " ";
	 				}
	 				cout << n - sum << "\n";
 				}
 				else
 					cout << "NO\n";
 			}
 		}
 	}
    return 0;
}
