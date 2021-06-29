#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
    int n, k;
    string s;

    cin >> n >> k >> s;
    int best = 0;
	for (int i = 1; i < n; ) {
		if (s[i] < s[i % (best + 1)]) {
			best = i;
			i++;
		}
		else if (s[i] > s[i % (best + 1)]) {
			break;
		}
		else {
			int j = i;
			while (j < n && s[j % (best + 1)] == s[j])
				j++;
			if (j == n or s[j % (best + 1)] < s[j]) {
				break;
			}
			else {
				best = j;
				i = j + 1;
			}
		}
	}
	// cout << best << "\n";
	for (int i = 0; i < k; i++) cout << s[i % (best + 1)];
	cout << "\n";
	return 0;
}
