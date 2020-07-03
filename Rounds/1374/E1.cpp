#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int main() {
	optimizar_io
	int n, k, t, a, b;	
	priority_queue<int,vector<int>,greater<int>> alice, bob, both;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> t >> a >> b;
		if (a == 1 and b == 1)
			both.push(t);
		else if (a == 1 and b == 0)
			alice.push(t);
		else if (a == 0 and b == 1)
			bob.push(t);
	}
	int cnt1 = 0, cnt2 = 0, sum = 0;
	while (!alice.empty() or !bob.empty() or !both.empty()) {
		//cout << alice.size() << " " << bob.size() << " " << both.size() << "\n";
		if (cnt1 >= k and cnt2 >= k) {
			cout << sum << "\n";
			return 0;
		}
		if (!alice.empty() and bob.empty() and both.empty()) {
			sum += alice.top();
			alice.pop();
			cnt1++;
		}
		else if (alice.empty() and !bob.empty() and both.empty()) {
			sum += bob.top();
			bob.pop();
			cnt2++;
		}
		else if (alice.empty() and bob.empty() and !both.empty()) {
			sum += both.top();
			both.pop();
			cnt1++;
			cnt2++;
		}
		else if (!alice.empty() and !bob.empty() and both.empty()) {
			if (cnt1 < k) {
				sum += alice.top();
				alice.pop();
				cnt1++;	
			}
			if (cnt2 < k) {
				sum += bob.top();
				bob.pop();
				cnt2++;		
			}
		}
		else if (!alice.empty() and bob.empty() and !both.empty()) {
			if (cnt2 < k) {
				sum += both.top();
				both.pop();
				cnt1++;
				cnt2++;		
			}
			else {
				if (alice.top() < both.top()) {
					sum += alice.top();
					alice.pop();
					cnt1++;
				}
				else {
					sum += both.top();
					both.pop();
					cnt1++;
					cnt2++;		
				}
			}
		}
		else if (alice.empty() and !bob.empty() and !both.empty()) {
			if (cnt1 < k) {
				sum += both.top();
				both.pop();
				cnt1++;
				cnt2++;
			}
			else {
				if (bob.top() < both.top()) {
					sum += bob.top();
					bob.pop();
					cnt2++;	
				}
				else {
					sum += both.top();
					both.pop();
					cnt1++;
					cnt2++;		
				}
			}
		}
		else if (!alice.empty() and !bob.empty() and !both.empty()) {
			if (cnt1 < k and cnt2 < k) {
				if (alice.top() + bob.top() > both.top()) {
					sum += both.top();
					both.pop();
					cnt1++;
					cnt2++;
				}
				else {
					sum += alice.top() + bob.top();
					alice.pop();
					cnt1++;
					bob.pop();
					cnt2++;
				}
			}
			else if (cnt1 < k and cnt2 >= k) {
				if (alice.top() < both.top()) {
					sum += alice.top();
					alice.pop();
					cnt1++;
				}
				else {
					sum += both.top();
					both.pop();
					cnt1++;
					cnt2++;		
				}
			}
			else if (cnt1 >= k and cnt2 < k) {
				if (bob.top() < both.top()) {
					sum += bob.top();
					bob.pop();
					cnt2++;	
				}
				else {
					sum += both.top();
					both.pop();
					cnt1++;
					cnt2++;		
				}
			}
		}
	}
	if (cnt1 >= k and cnt2 >= k)
		cout << sum << "\n";
	else
		cout << "-1\n";
	return 0;
}
