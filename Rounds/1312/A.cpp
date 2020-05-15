#include <iostream>
using namespace std;

int main() {

    int tc, n, m;

    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        cout << (n % m == 0 ? "YES" : "NO") << "\n";
    }
    return 0;
}
