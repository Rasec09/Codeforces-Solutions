#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
#define MAXN 100010
#define LOGN 20

typedef pair<int,int> ii;

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
			sparse[i][j] = (A[x] > A[y]) ? x : y;
		}
	}
}

int rmq(int i, int j) {
	int k = logs[j - i + 1];
	int x = sparse[i][k];
	int y = sparse[j - (1 << k) + 1][k];
	return A[x] > A[y] ? x : y;
}

int main() {
	optimizar_io
	int n;
	vector<pair<int,int>> laptop;

	cin >> n;
	laptop.assign(n, ii(0,0));
	for (int i = 0; i < n; i++) cin >> laptop[i].first >> laptop[i].second;
	sort(laptop.begin(), laptop.end());
	for (int i = 0; i < n; i++)
		A[i] = laptop[i].second;
	preprocess(n);
	bool answer = false;
	for (int i = n - 1; i > 0; i--) {
		int j = rmq(0, i - 1);
		if (laptop[i].first > laptop[j].first and A[i] < A[j]) {
			answer = true;
			break;
		}
	}
	cout << (answer ? "Happy Alex\n" : "Poor Alex\n");
	return 0;
}
