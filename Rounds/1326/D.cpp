#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

vector<int> kmpPreprocess(string &P, int m) {
    vector<int> b(m + 1);
    int i = 0, j = -1; b[0] = -1;
    while (i < m) {
        while (j >= 0 && P[i] != P[j]) j = b[j];
        i++; j++;
        b[i] = j;
    }
    return b;
}

int main() {
    optimizar_io
    int t;
    string s;
    
    cin >> t;
    while (t--) {
        cin >> s;
        int l = 0, r = s.size() - 1;
        while (s[l] == s[r] and l < r) {
            l++;
            r--;
        }
        if (l >= r) {
            cout << s << "\n";
            continue;
        }
        string w = s.substr(l, r - l + 1);
        string tmp = w;
        reverse(tmp.begin(), tmp.end());
        string a = w + "#" + tmp, middle = "";
        int n = a.size();
        vector<int> preffix = kmpPreprocess(a, n);
        if (preffix[n] > middle.size()) {
            middle = a.substr(n - preffix[n], preffix[n]);
        }
        string b = tmp + "#" + w;
        preffix = kmpPreprocess(b, n);
        if (preffix[n] > middle.size()) {
            middle = b.substr(n - preffix[n], preffix[n]);
        }
        tmp = s.substr(0, l);
        cout << tmp << middle;
        reverse(tmp.begin(), tmp.end());
        cout << tmp << "\n";
    }
    return 0;
}
