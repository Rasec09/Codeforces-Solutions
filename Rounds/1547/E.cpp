#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

struct SegmentTree {
	
	vector<int> stree;

	SegmentTree(vector<int> &arr, int N) {
		stree.assign(getSegmentTreeSize(N), 0);
		buildTree(arr, 1, 0, N - 1);
	}

	void buildTree(vector<int> &arr, int nodo, int L, int R) {
		if (L == R)
			stree[nodo] = arr[L];
		else {
			int mid = (L + R) / 2, leftIdx = 2 * nodo, rightIdx = 2 * nodo + 1;
			buildTree(arr, leftIdx, L, mid);
			buildTree(arr, rightIdx, mid + 1, R);
			stree[nodo] = min(stree[leftIdx], stree[rightIdx]);
		}
	}

	int query(int nodo, int L, int R, int i, int j) {
		if (L >= i && R <= j)
			return stree[nodo];
		
		int mid = (L + R)/2, leftIdx = 2 * nodo, rightIdx = 2 * nodo + 1;
		if (j <= mid)
			return query(leftIdx, L, mid, i, j);
		if (i > mid)
			return query(rightIdx, mid + 1, R, i, j);
		
		int leftResult = query(leftIdx, L, mid, i, mid);
		int rightResult = query(rightIdx, mid + 1, R, mid + 1, j);
		int result = min(leftResult, rightResult);
		return result;
	}

	int getSegmentTreeSize(int N) {
		int size = 1;
		for(; size < N; size <<= 1);
		return size << 1;
	}
};

int main() {
	optimizar_io
	int tc, n, k;

	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		vector<int> pos(k);
		for (int i = 0; i < k; i++) cin >> pos[i];
		vector<int> t(k);
		for (int i = 0; i < k; i++) cin >> t[i];
		vector<int> a(n, 2e9), b(n, 2e9);
		for (int i = 0; i < k; i++) {
			a[pos[i] - 1] = t[i] - pos[i];
			b[pos[i] - 1] = t[i] + pos[i];
		}
		SegmentTree st1(a, n), st2(b, n);
		vector<int> ans(n);
		for (int i = 0; i < n; i++) {
			ans[i] = min(i + 1 + st1.query(1, 0, n - 1, 0, i), st2.query(1, 0, n - 1, i, n - 1) - (i + 1));
		}
		for (auto x : ans) cout << x << " ";
		cout << "\n";
	}
	return 0;
}
