#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
    int q, n;
	ll k;
	string s;

	cin >> q;
	while (q--) {
		cin >> n >> k >> s;
		queue<int> zeros;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '0')
				zeros.push(i);
		}
		int pos = 0;
		while (!zeros.empty() and k and pos < n) {
			ll diff = zeros.front() - pos;
			if (k >= diff) {
				k -= diff;
				swap(s[pos], s[zeros.front()]);
				zeros.pop();
				pos++;
			}
			else {
				pos = zeros.front() - k;
				swap(s[pos], s[zeros.front()]);
				zeros.pop();
				k = 0;
			}
		}
		cout << s << "\n";
	}
	return 0;
}
