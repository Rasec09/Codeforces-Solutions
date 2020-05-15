#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
#define MAXN 1000010

char arr[MAXN];

struct Node {
  int parentesisAbiertos, parentesisCerrados;

  void make_Node(char parentesis) {	
    if (parentesis == '(')
      parentesisAbiertos = 1, parentesisCerrados = 0;
    else
      parentesisAbiertos = 0, parentesisCerrados = 1;
  }

  void merge(Node left, Node right) { 
    int matched = min(left.parentesisAbiertos, right.parentesisCerrados);
    parentesisAbiertos = left.parentesisAbiertos + right.parentesisAbiertos - matched;
    parentesisCerrados = left.parentesisCerrados + right.parentesisCerrados - matched;
  }

  bool getValue() {
    return (parentesisAbiertos == 0 && parentesisCerrados == 0);
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

  void update(int nodo, int L, int R, int idx) {
    if (L == R) {
      if (arr[idx] == '(') {
        arr[idx] = ')';
        stree[nodo].make_Node(')');
      }
      else {
        arr[idx] = '(';
        stree[nodo].make_Node('(');
      }
      return;
    }
    int mid = (L + R)/2, leftIdx = 2 * nodo, rightIdx = 2 * nodo + 1;
    if (idx <= mid)
      update(leftIdx, L, mid, idx);
    else
      update(rightIdx, mid + 1, R, idx);
    stree[nodo].merge(stree[leftIdx], stree[rightIdx]);
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

  cin >> n >> arr;
  if (count(arr, arr + n, '(') != count(arr, arr + n, ')')) return cout << "-1\n", 0;
  SegmentTree st(n);
  if (st.query(1, 0, n - 1, 0, n - 1).getValue()) {
    cout << "0\n";
  }
  else {
    int ans = 0, l = 0, r = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i] == '(')
        l++;
      else
        r++;
      if (l == r) {
        //cout << i - 2 * l + 1 << " " << i << " ";
        if (!st.query(1, 0, n - 1, i - 2*l + 1, i).getValue()) {
          ans += 2 * l;
        }
        l = 0;
        r = 0;
      }
    }
    cout << min(ans, n) << "\n";
  }
  return 0;
}
