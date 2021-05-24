#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

vector<int> maxPermutation(int q[], int n) {
	vector<int> a(n, -1);
	for (int i = n - 1; i > 0; i--) {
		if (q[i] != q[i - 1])
			a[i] = q[i];
	}
	a[0] = q[0];
	set<int> nums;
	for (int i = 1; i <= n; i++) {
		nums.insert(i);
	}
	for (int i = 0; i < n; i++) {
		if (a[i] != -1)
			nums.erase(a[i]);
	}
	int last = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] != -1) {
			last = a[i];
		} 
		else {
			auto it = nums.lower_bound(last);
			it--;
			a[i] = *it;
			nums.erase(it);			
		}
	}
	// for (int i = 0; i < n; i++) cout << a[i] << " ";
	// cout << "\n";
	return a;
}

vector<int> minPermutation(int q[], int n) {
	vector<int> a(n, -1);
	for (int i = n - 1; i > 0; i--) {
		if (q[i] != q[i - 1])
			a[i] = q[i];
	}
	a[0] = q[0];
	set<int> nums;
	for (int i = 1; i <= n; i++) {
		nums.insert(i);
	}
	for (int i = 0; i < n; i++) {
		if (a[i] != -1)
			nums.erase(a[i]);
	}
	int last = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] != -1) {
			last = a[i];
		} 
		else {
			auto it = nums.begin();
			a[i] = *it;
			nums.erase(it);			
		}
	}
	// for (int i = 0; i < n; i++) cout << a[i] << " ";
	// cout << "\n";
	return a;	
}

int main() {
	optimizar_io
    int tc, n, q[200010];

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> q[i];
		vector<int> a = minPermutation(q, n);
		vector<int> b = maxPermutation(q, n);
		for (auto x : a) cout << x << " ";
		cout << "\n";
		for (auto x : b) cout << x << " ";
		cout << "\n";
	}
	return 0;
}
