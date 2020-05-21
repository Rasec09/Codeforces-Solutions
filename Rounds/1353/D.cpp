#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

struct intervalo {
	int l, r, size;
	intervalo(int _l, int _r) : l(_l), r(_r), size(_r - _l + 1) {}
	bool operator<(const intervalo &x) const {
		if (size < x.size)
			return true;
		else if (size > x.size)
			return false;
		else 
			return l > x.l;
	}
};

int main() {
    optimizar_io
 	int tc, n;
 	
 	cin >> tc;
 	while (tc--) {
 		cin >> n;
 		vector<int> ans(n);
 		priority_queue<intervalo> pq;
 		pq.push(intervalo(0, n - 1));
 		int cnt = 0;
 		while (!pq.empty()) {
 			intervalo i = pq.top();
 			pq.pop();
 			int pos;
 			if (i.size % 2 == 0)
 				pos = (i.l + i.r - 1) / 2;
 			else
 				pos = (i.l + i.r) / 2;
 			ans[pos] = ++cnt;
 			if (pos - 1 >= i.l)
 				pq.push(intervalo(i.l, pos - 1)); 
 			if (pos + 1 <= i.r)
 				pq.push(intervalo(pos + 1, i.r));
 		}
 		for (int a : ans)
 			cout << a << " ";
 		cout << "\n";
 	}
    return 0;
}
