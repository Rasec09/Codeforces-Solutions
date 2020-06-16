#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int x, arr[1000010];

struct SegmentTree {
	
	int *stree;

	SegmentTree(int N) {		
		stree = new int[getSegmentTreeSize(N)];
		buildTree(1, 0, N - 1);
	}

	void buildTree(int nodo, int L, int R) {
		if (L == R)
			stree[nodo] = arr[L] % x;
		else {
			int mid = (L + R)/2, leftIdx = 2 * nodo, rightIdx = 2 * nodo + 1;
			buildTree(leftIdx, L, mid);
			buildTree(rightIdx, mid + 1, R);
			stree[nodo] = (stree[leftIdx] + stree[rightIdx]) % x;
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
		return (leftResult + rightResult) % x;
	}

	int getSegmentTreeSize(int N) {
		int size = 1;
		for(; size < N; size <<= 1);
		return size << 1;
	}
};


int main() {
    optimizar_io
	int tc, n;

	cin >> tc;
	while (tc--) {
		cin >> n >> x;
		bool possible = false;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			if (arr[i] % x != 0)
				possible = true;
		}
		if (possible) {
			SegmentTree st(n);
			int sum = st.query(1, 0, n - 1, 0, n - 1);
			if (sum) {
				cout << n << "\n";
			}
			else {
				int ans = -1;
				for (int i = 0; i < n; i++) {
					if (i) {
						int l = st.query(1, 0, n - 1, 0, i - 1);
						if (l)
							ans = max(ans, i);
					}
					if (i != n - 1) {
						int r = st.query(1, 0, n - 1, i + 1, n - 1);
						if (r)
							ans = max(ans, n - 1 - i);
					}
				}
				cout << ans << "\n";
			}
		}
		else {
			cout << "-1\n";
		}
	}
    return 0;
}
