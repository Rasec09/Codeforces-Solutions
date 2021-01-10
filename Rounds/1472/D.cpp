#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main()
{
	optimizar_io 
	int tc, n, a[200010];

	cin >> tc;
	while (tc--)
	{
		cin >> n;
		priority_queue<int> nums;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			nums.push(a[i]);
		}
		int turn = 1;
		ll alice = 0, bob = 0;
		while (!nums.empty()) {
			if (turn) {
				if (nums.top() % 2 == 0)
					alice += nums.top();
				nums.pop();
			}
			else {
				if (nums.top() % 2 == 1)
					bob += nums.top();
				nums.pop();
			}
			turn = 1 - turn;
		}
		if (alice > bob)
			cout << "Alice\n";
		else if (bob > alice)
			cout << "Bob\n";
		else
			cout << "Tie\n";
	}
	return 0;
}
