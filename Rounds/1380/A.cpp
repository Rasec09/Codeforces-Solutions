#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
#define MAXN 100010
#define LOGN 20

int A[MAXN];
int sparse[MAXN][LOGN];
int logs[MAXN];

void preprocess(int n) {
	for (int i = 2; i <= n; i++)
		logs[i] = logs[i >> 1] + 1;

	for (int i = 0; i < n; i++)
		sparse[i][0] = i;

	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 0; i + (1 << j) - 1 < n; i++) {
			int x = sparse[i][j - 1];
			int y = sparse[i + (1 << (j - 1))][j - 1];
			sparse[i][j] = (A[x] < A[y]) ? x : y;
		}
	}
}

int rmq(int i, int j) {
	int k = logs[j - i + 1];
	int x = sparse[i][k];
	int y = sparse[j - (1 << k) + 1][k];
	return A[x] < A[y] ? x : y;
}

int main() {
	optimizar_io
	int tc, n;

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> A[i];
		preprocess(n);
		vector<pair<int,int>> ii;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++)
				if (A[j] > A[i])
					ii.push_back({i, j});
		}
		bool possible = false;
		for (int i = 0; i < ii.size(); i++) {
			if (ii[i].second + 1 <= n - 1) {
				int idx = rmq(ii[i].second + 1, n - 1);
				if (A[idx] < A[ii[i].second]) {
					cout << "YES\n";
					cout << ii[i].first + 1 << " " << ii[i].second + 1 << " " << idx + 1 << "\n";
					possible = true;
					break;
				}
			}
		}
		if (!possible)
			cout << "NO\n";
	}
	return 0;
}
