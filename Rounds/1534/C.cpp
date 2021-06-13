#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

struct UnionFind {
	
	int numSets;
	int *padre;
	int *rango;
	int *numVertices;

	UnionFind(int N) : numSets(N) {
		padre = new int[N + 1];
		rango = new int[N + 1];
		numVertices = new int[N + 1];
		for (int i = 0; i <= N; ++i) {
			padre[i] = i;
			rango[i] = 0;
			numVertices[i] = 1;
		}
	}

	int findSet(int x) {
        return (x == padre[x]) ? x : (padre[x] = findSet(padre[x]));
    }

    bool isSameSet(int x, int y) {
       	return findSet(x) == findSet(y);
    }

    void unionSet(int x, int y) {
        int xRoot = findSet(x);
        int yRoot = findSet(y);
		if (!isSameSet(xRoot, yRoot)) {
			if (rango[xRoot] > rango[yRoot]) {
				padre[yRoot] = xRoot;
				numVertices[xRoot] += numVertices[yRoot];
			}
			else {
				padre[xRoot] = yRoot;
				numVertices[yRoot] += numVertices[xRoot];
				if (rango[xRoot] == rango[yRoot])
					rango[yRoot]++;
			}
            numSets--;
        }
    }

    int sizeOfSet(int x) {
    	return numVertices[findSet(x)];
    }
};

ll mod(ll a, ll b) {
	return ((a % b) + b) % b;
}

ll powMod(ll a, ll n, ll m) {
	ll result = 1;
	while (n) {
		if (n & 1)
			result = mod(result * a, m);
		a = mod(a * a, m);
		n >>= 1;
	}
	return result;
}

int main() {
	optimizar_io
	int tc, n, a[2][400010];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++)
				cin >> a[i][j];
		}
		UnionFind ds(n);
		for (int i = 0; i < n; i++) {
			ds.unionSet(a[0][i], a[1][i]);
		}
		cout << powMod(2, ds.numSets, 1e9 + 7) << "\n";
	}
	return 0;
}
