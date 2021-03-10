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

void merge(vector<int> &d, int l, int r, int lvl) {
	if (l == r) {
		d[l] = lvl;
		return;
	}
	if (l < r) {
		int mid = rmq(l, r);
		d[mid] = lvl;
		merge(d, l, mid - 1, lvl + 1);
		merge(d, mid + 1, r, lvl + 1); 
	}
}

int main() {
	optimizar_io
    int tc, n;

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> A[i];
		preprocess(n);
		vector<int> d(n);
		merge(d, 0, n - 1, 0);
		for (int i = 0; i < n; i++) {
			cout << d[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
