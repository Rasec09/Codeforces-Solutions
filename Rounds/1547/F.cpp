#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
#define MAXN 1000010

int arr[MAXN];

int gcd(int a, int b) {
	return (b == 0 ? a : gcd(b, a % b));
}

struct Node {
	
	int g;

	void make_Node(int v) {
		g = v;
	}

	void merge(Node left, Node right) {
		g = gcd(left.g, right.g);
	}
};

struct SegmentTree {
	
	Node *stree;

	SegmentTree(int N) {
		stree = new Node[getSegmentTreeSize(N)];
		buildTree(1, 0, N - 1);
	}

	void buildTree(int nodo, int L, int R) {
		if (L == R)
			stree[nodo].make_Node(arr[L]);
		else {
			int mid = (L + R)/2, leftIdx = 2 * nodo, rightIdx = 2 * nodo + 1;
			buildTree(leftIdx, L, mid);
			buildTree(rightIdx, mid + 1, R);
			stree[nodo].merge(stree[leftIdx], stree[rightIdx]);
		}
	}

	Node query(int nodo, int L, int R, int i, int j) {
		if (L >= i && R <= j)
			return stree[nodo];
		
		int mid = (L + R)/2, leftIdx = 2 * nodo, rightIdx = 2 * nodo + 1;
		if (j <= mid)
			return query(leftIdx, L, mid, i, j);
		if (i > mid)
			return query(rightIdx, mid + 1, R, i, j);
		
		Node leftResult = query(leftIdx, L, mid, i, mid);
		Node rightResult = query(rightIdx, mid + 1, R, mid + 1, j);
		Node result;
		result.merge(leftResult, rightResult);
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
	int tc, n;

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> arr[i], arr[n + i] = arr[i];
		n *= 2;
		SegmentTree st(n);
		int l = 1, r = n / 2, g = st.query(1, 0, n - 1, 0, n - 1).g;
		while (l < r) {
			int m = (l + r) / 2;
			auto check = [](SegmentTree &st, int k, int g, int n) -> bool {
				for (int i = 0; i <= n / 2; i++) {
					if (st.query(1, 0, n - 1, i, i + k - 1).g > g)
						return true;
				}
				return false;
			};
			if (check(st, m, g, n))
				l = m + 1;
			else
				r = m;
		}
		cout << l - 1 << "\n";
	}
	return 0;
}
