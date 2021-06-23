#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int isPowerOfTwo(vector<int> &powerOfTwo, int x) {
	for (int i = 0; i < powerOfTwo.size(); i++) {
		if (powerOfTwo[i] == x) {
			return i;
		}
	}
	return -1;
}

int main() {
	optimizar_io
	int tc, n;
	vector<int> powerOfTwo;

	powerOfTwo.push_back(2);
	while (powerOfTwo.back() < 1e9) {
		powerOfTwo.push_back(powerOfTwo.back() * 2);
	}
	cin >> tc;
	while (tc--) {
		cin >> n;
		if (n & 1) {
			cout << "Bob\n";
		}
		else {
			int pos = isPowerOfTwo(powerOfTwo, n); 
			if (pos == -1)
				cout << "Alice\n";
			else
				cout << (pos & 1 ? "Alice" : "Bob") << "\n";
		}
	}
	return 0;
}
