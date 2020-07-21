#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
#define MAXN 200010
#define LOGN 20

int A[MAXN];
int sparse[MAXN][LOGN];
int logs[MAXN];

void preprocess(int n) {
    for (int i = 2; i <= n; i++) logs[i] = logs[i >> 1] + 1;

    for (int i = 0; i < n; i++) sparse[i][0] = i;

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

bool check1(int n, int pos) {
    int idx = rmq(pos, n - 1);
    for (int i = pos; i + 1 < idx; i++) {
        if (A[i] > A[i + 1])
            return false;
    }
    for (int i = idx; i + 1 < n; i++) {
        if (A[i] < A[i + 1])
            return false;
    }
    return true;
}

int isSorted(int n) {
    for (int i = 0; i + 1 < n; i++)
        if (A[i] > A[i + 1])
            return false;
    return true;
}

int main() {
    optimizar_io
    int tc, n;
    
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> A[i];
        preprocess(n);
        if (isSorted(n))
            cout << "0\n";
        else {
            int left = 2, right = n + 1;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (check1(n, n - mid))
                    left = mid + 1;
                else
                    right = mid;
            }
            cout << n - left + 1 << "\n";
        }
    }
    return 0;
}
