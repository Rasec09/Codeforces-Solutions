#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int q, n, a[102];
	
	cin >> q;
	while (q--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<int> possible(n, 1);
		for (int i = 0; i < n; i++) {
			int mn = i;
			for (int j = i; j < n; j++) {
				if (a[j] < a[mn])
					mn = j;
			}
			for (int j = mn - 1; possible[j] and j >= i; j--) {
				swap(a[j], a[j + 1]);
				possible[j] = 0;
			}
		}
		for (int i = 0; i < n; i++) cout << a[i] << " ";
		cout << "\n";
	}
	return 0;
}
