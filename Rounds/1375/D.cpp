#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int findMEX(map<int,int> &freq) {
	int mex = 0;
	for (auto f : freq) {
		if (f.first != mex)
			return mex;
		mex++;
	}
	return mex;
}

bool isSorted(int a[], int n) {
	for (int i = 0; i + 1 < n; i++) {
		if (a[i] > a[i + 1])
			return false;
	}
	return true;
}

int main() {
	optimizar_io
	int tc, n, a[1010];
	map<int,int> freq;

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			freq[a[i]]++;
		}
		vector<int> ans;
		set<int> diff;
		diff.insert(a[0]);
		for (int i = 1; i < n; i++) {
			if (diff.count(a[i])) {
				freq[a[i]]--;
				int mex = findMEX(freq);
				a[i] = mex;
				freq[mex]++;
				ans.push_back(i);
			}
			diff.insert(a[i]);
		}
		int idx;
		while (!isSorted(a, n)) {
			int mex = findMEX(freq);
			if (mex != n) {
				freq.erase(a[mex]);
				freq[mex]++;
				a[mex] = mex;
				ans.push_back(mex);
			}
			else {
				for (int j = 0; j < n; j++) {
					if (a[j] != j) {
						idx = j;
						break;
					}
				}
				freq.erase(a[idx]);
				freq[n]++;
				a[idx] = n;
				ans.push_back(idx);	
			}
			
		}
		cout << ans.size() << "\n";
		for (int x : ans)
			cout << x + 1 << " ";
		cout << "\n";
		freq.clear();
	}
	return 0;
}
