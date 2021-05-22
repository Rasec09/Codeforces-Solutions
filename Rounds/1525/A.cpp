#include <bits/stdc++.h>
using namespace std;

double calcula(double e, double w) {
	double ans = 100.0 * e / (e + w);
	return ans; 
}

int main() {

	int tc; 
	double k;

	cin >> tc;
	while (tc--) {
		cin >> k;
		int e = 1, w = 0;
		while (fabs(k - calcula(e, w)) > 1e-9) {
			if (calcula(e, w) > k) {
				w++;
			}
			else {
				e++;
			}
		}
		cout << e + w << "\n";
	}
	return 0;
}
