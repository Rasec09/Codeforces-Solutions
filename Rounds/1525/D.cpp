#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

const int INF = 1e9;
int memo[2510][5010];
vector<int> A, B;

int dp(int i, int j) {
	if (i == A.size()) return 0;
	if (j == B.size() and i < A.size()) return INF;
	if (memo[i][j] != -1) return memo[i][j];
	return memo[i][j] = min(dp(i + 1, j + 1) + abs(A[i] - B[j]), dp(i, j + 1));
}

int main() {
	optimizar_io
	int n, a[5010];
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		if (a[i] & 1)
			A.push_back(i);
		else
			B.push_back(i);
	}
	memset(memo, -1, sizeof(memo));
	cout << dp(0, 0) << "\n";
	return 0;
}
