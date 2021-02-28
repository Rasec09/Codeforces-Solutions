#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
#define MAXN 100010
#define LOGN 20

int A[MAXN];
int sparse[MAXN][LOGN];
int logs[MAXN];

void preprocess(int n) {
	
	int i, j;

	for (i = 2; i <= n; i++)
		logs[i] = logs[i >> 1] + 1;

	for (i = 0; i < n; i++)
		sparse[i][0] = i;

	for (j = 1; (1 << j) <= n; j++) {
		for (i = 0; i + (1 << j) - 1 < n; i++) {
			int x = sparse[i][j - 1];
			int y = sparse[i + (1 << (j - 1))][j - 1];
			sparse[i][j] = (A[x] >= A[y]) ? x : y;
		}
	}
}

int rmq(int i, int j) {
	int k = logs[j - i + 1];
	int x = sparse[i][k];
	int y = sparse[j - (1 << k) + 1][k];
	return A[x] >= A[y] ? x : y;
}

int main() {
	optimizar_io
	int tc, n;

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> A[i];
		preprocess(n);
		int r = n - 1;
		vector<int> ans;
		while (r >= 0) {
			int idx = rmq(0, r);
			for (int i = idx; i <= r; i++)
				ans.push_back(A[i]);
			r = idx - 1;
		}
		for (int a : ans)
			cout << a << " ";
		cout << "\n";
	}
	return 0;
}
