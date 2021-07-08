#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;

ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}

int main() {
	optimizar_io
	int tc;
	ll a, b;

	cin >> tc;
	while (tc--) {
		cin >> a >> b;
		if (a == b) {
			cout << "0 0\n";
			continue;
		}
		if (b > a) swap(a, b);
		ll exc = a - b, g = gcd(a, b);
		if (exc == g) {
			cout << exc << " " << 0 << "\n";
		}
		else {
			ll rem = a % exc;
			cout << exc << " " << min(rem, exc - rem) << "\n";
		}
	}
	return 0;
}
/* 
* Problema: maximizar el gcd de dos numeros sumandoles a ambos 1 o -1.
* Solucion: Si a > b entonces gcd(a, b) = gcd(a - b, b)
* ademas sabemos que gcd(x, y) <= min(x, y) 
* entonces el valor maximo que puede alcanzar el gcd es a - b.
* Para obtener el valor deseado necesitamos que a y b sean dividibles por la diferencia,
* contamos cuantas operaciones de suma y resta necesitariamos y nos quedamos con la mejor.
* Esto es posible porque:
* exc = a - b => a = b + exc => a ≡ (b mod exc) => a mod exc = b mod exc
*/
