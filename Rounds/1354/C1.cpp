#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

double PI = acos(-1);

double AreaPoligono(int n) {
  double angulo = 360.0 / n;
  double interno = (180.0 - angulo) / 2.0;
  //double r = 0.5 / cos(interno * PI / 180);
  //double area = (n * r * r * sin(angulo * PI / 180.0)) / 2.0;*/
  double apotema = 0.5 * tan(interno * PI / 180.0);
  //double area = (n * 1.0 * apotema) / 2.0;  
  return apotema * 2.0;
}

int main() {
    optimizar_io
  int tc, n; 

  cin >> tc;
  while (tc--) {
    cin >> n;
    n *= 2;
    double area = AreaPoligono(n);
    cout << fixed;
    cout << setprecision(9) << area << "\n";
  }
    return 0;
}
