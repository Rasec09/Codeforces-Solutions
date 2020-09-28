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
		cin >> n >> s;
		vector<int> marked(n);
		for (int i = 1; i < n; i++) {
			if (i & 1) { //Raze
				bool finish = false;
				for (int j = 0; j < n; j += 2) {
					if (!marked[j] and ((s[j] - '0') % 2 == 0)) {
						marked[j] = 1;
						finish = true;
						break;
					}
				}
				if (!finish) {
					for (int j = 0; j < n; j += 2) {
						if (!marked[j]) {
							marked[j] = 1;
							break;
						}
					}	
				}
			}
			else {
				bool finish = false;
				for (int j = 1; j < n; j += 2) {
					if (!marked[j] and ((s[j] - '0') & 1)) {
						marked[j] = 1;
						finish = true;
						break;
					}
				}
				if (!finish) {
					for (int j = 1; j < n; j += 2) {
						if (!marked[j]) {
							marked[j] = 1;
							break;
						}
					}	
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (!marked[i]) {
				cout << ((s[i] - '0') & 1 ? "1\n" : "2\n");				
			}
		}
	}
	return 0;
}
