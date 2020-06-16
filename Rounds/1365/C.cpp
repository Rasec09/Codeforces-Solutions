#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
    optimizar_io
    int n, x;
    map<int,int> a, b, freq;

    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> x;
    	a[x] = i;
    }
    for (int i = 0; i < n; i++) {
    	cin >> x;
    	b[x] = i;
    }
    for (int i = 1; i <= n; i++) {
    	int shiff = b[i] - a[i];
    	if (shiff < 0)
    		shiff = n - a[i] + b[i];
    	//cout << shiff << "\n";
    	freq[shiff]++;
    }
    int mx = -1;
    for (auto f : freq) {
    	mx = max(mx, f.second);
    }
    cout << mx << "\n";
    return 0;
}
