#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
#define MAXN 200010
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

bool check(int a[], int n, int x, int k) {
	for (int i = 1; i <= n; i++) {
		A[i] = (a[i - 1] >= x ? 1 : -1);
		if (i)
			A[i] += A[i - 1];
	}
	preprocess(n + 1);
	for (int i = k; i <= n; i++) {
		int idx = rmq(0, i - k);
		if (A[i] - A[idx] > 0)
			return true;
	}
	return false;
}

int main() {
	optimizar_io
    int n, k, a[200010];

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	int l = 1, r = n + 1;
	while (l < r) {
		int mid = (l + r) / 2;
		if (check(a, n, mid, k))
			l = mid + 1;
		else
			r = mid;
	}
	cout << l - 1 << "\n";
	return 0;
}
