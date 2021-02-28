#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
    int ones, zeros, k, size;
	string x, y;

	cin >> zeros >> ones >> k;
	size = zeros + ones;
	x.assign(ones + zeros, '0');
	for (int i = 0; i < ones; i++) x[i] = '1';
	if (k == 0) return cout << "Yes\n" << x << "\n" << x << "\n", 0;
	if (k > size - 2 or ones == 1 or ones == size) return cout << "No\n", 0;
	y.push_back('1'); ones--; // El del principio
	y.push_back('0'); zeros--;
	for (int i = 0; i + 1 < k; i++) {
		if (ones > 1) {
			y.push_back('1');
			ones--;
		}
		else {
			y.push_back('0');
			zeros--;
		}
	}
	y.push_back('1'); ones--;
	while (zeros--) y.push_back('0');
	reverse(y.begin(), y.end());
	while (ones--) y.push_back('1');
	reverse(y.begin(), y.end());
	cout << "Yes\n" << x << "\n" << y << "\n";
	return 0;
}
/*
1...1xxx0...0
1...0xxx1...0
*/
