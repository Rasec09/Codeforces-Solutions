#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int a[100010], l[100010], r[100010];

struct Node {
    
    int prefixSum;
    int suffixSum;
    int sum;
    int maxSum;
    
    Node() {}
    Node(int p, int s, int _sum, int mx) : prefixSum(p), suffixSum(s), sum(_sum), maxSum(mx) {}
};

Node merge(Node l, Node r) {
    int sum = l.sum + r.sum;
    int p = max(l.prefixSum, l.sum + r.prefixSum);
    int s = max(r.suffixSum, r.sum + l.suffixSum);
    int mx = max(l.maxSum, max(r.maxSum, l.suffixSum + r.prefixSum));
    return Node(p, s, sum, mx);
}

struct SegmentTree {
    
    Node *stree;

    SegmentTree(int N) {
        stree = new Node[getSegmentTreeSize(N)];
        buildTree(1, 0, N - 1);
    }

    void buildTree(int nodo, int L, int R) {
        if (L == R)
            stree[nodo] = Node(a[L], a[L], a[L], a[L]);
        else {
            int mid = (L + R)/2, leftIdx = 2 * nodo, rightIdx = 2 * nodo + 1;
            buildTree(leftIdx, L, mid);
            buildTree(rightIdx, mid + 1, R);
            stree[nodo] = merge(stree[leftIdx], stree[rightIdx]);
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
        Node result = merge(leftResult, rightResult);
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
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    stack<int> s;
    for (int i = 0; i < n;) {
        if (s.empty() or a[s.top()] > a[i])
            s.push(i++);
        else {
            int tope = s.top();
            s.pop();
            r[tope] = i;
            if (s.empty() or a[s.top()] == a[tope])
                l[tope] = -1;
            else
                l[tope] = s.top();
        }
    }
    while (!s.empty()) {
        int tope = s.top();
        s.pop();
        r[tope] = n;
        if (s.empty() or a[s.top()] == a[tope])
            l[tope] = -1;
        else
            l[tope] = s.top();
    }
    /*for (int i = 0; i < n; i++) {
        cout << l[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << r[i] << " ";
    }
    cout << "\n";*/
    SegmentTree st(n);
    int ans = numeric_limits<int>::min(), idx = -1;
    for (int i = 0; i < n; i++) {
        int left = min(l[i] + 1, i);
        int right = max(r[i] - 1, i);
        //cout << "[" << left << "," << i << "] [" << i << "," << right << "]\n";
        int leftSum = st.query(1, 0, n - 1, left, i).suffixSum;
        int rightSum = st.query(1, 0, n - 1, i, right).prefixSum;
        //cout << leftSum << " " << rightSum << " " << leftSum + rightSum << "\n";
        if (ans < leftSum + rightSum - 2 * a[i]) {
            ans = leftSum + rightSum - 2 * a[i];
            idx = i;
        }
    }
    cout << ans << "\n";
    return 0;
}
