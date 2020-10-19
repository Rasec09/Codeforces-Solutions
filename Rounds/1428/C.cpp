#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
	optimizar_io
	int tc, n;
	string s;

	cin >> tc;
	while (tc--) {
		cin >> s;
		n = s.size();
		vector<int> deleted(n);
		stack<int> pila;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'A')
				pila.push(i);
			else {
				if (!pila.empty()) {
					deleted[i] = 1;
					deleted[pila.top()] = 1;
					pila.pop();
				}
			}
		}
		while (!pila.empty()) pila.pop();
		for (int i = 0; i < n; i++) {
			if (s[i] == 'B' and !deleted[i]) {
				if (pila.empty())
					pila.push(i);
				else {
					deleted[i] = 1;
					deleted[pila.top()] = 1;
					pila.pop();
				}
			}
		}
		while (!pila.empty()) pila.pop();
		cout << count(deleted.begin(), deleted.end(), 0) << "\n";
	}
	return 0;
}
