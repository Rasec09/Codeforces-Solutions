#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

vector<int> stree;

void update(int nodo, int L, int R, int idx, int value) {
	if (L == R) {
		stree[nodo] += value;
		return;
	}
	int mid = (L + R)/2, leftIdx = 2 * nodo, rightIdx = 2 * nodo + 1;
	if (idx <= mid)
		update(leftIdx, L, mid, idx, value);
	else
		update(rightIdx, mid + 1, R, idx, value);
	stree[nodo] = stree[leftIdx] + stree[rightIdx];
}

int query(int nodo, int L, int R, int i, int j) {
	if (L >= i && R <= j)
		return stree[nodo];
	int mid = (L + R) / 2, leftIdx = 2 * nodo, rightIdx = 2 * nodo + 1;
	if (j <= mid)
		return query(leftIdx, L, mid, i, j);
	if (i > mid)
		return query(rightIdx, mid + 1, R, i, j);
	int leftResult = query(leftIdx, L, mid, i, mid);
	int rightResult = query(rightIdx, mid + 1, R, mid + 1, j);
	return leftResult + rightResult;
}

int getSize(int N) {
	int size = 1;
	for(; size < N; size <<= 1);
	return size << 1;
}

int findKthElement(int nodo, int l, int r, int k) {
	if (l == r) return l;
	int left = 2 * nodo, right = 2 * nodo + 1, mid = (l + r) / 2;
	if (stree[left] >= k)
		return findKthElement(left, l, mid, k);
	else
		return findKthElement(right, mid + 1, r, k - stree[left]);
}

int main() {
    optimizar_io
	int n, q, x;

	cin >> n >> q;
	stree.assign(getSize(n + 1), 0);
	for (int i = 0; i < n; i++) {
		cin >> x;
		update(1, 0, n, x, 1);
	}
	/*for (int i = 1; i <= n; i++)
		cout << findKthElement(1, 0, n, i) << "\n";*/
	while (q--) {
		cin >> x;
		if (x > 0)
			update(1, 0, n, x, 1);
		else {
			x *= -1;
			int k = findKthElement(1, 0, n, x);
			update(1, 0, n, k, -1);
		}
	}
	if (query(1, 0, n, 0, n))
		cout << findKthElement(1, 0, n, 1) << "\n";
    else
    	cout << "0\n";
    return 0;
}
