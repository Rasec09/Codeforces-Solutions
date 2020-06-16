#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int turn[3];
vector<int> tablero;

int turno(int jugador, int pasos, int size, int &cnt) {
    turn[cnt % 3]++;
    //cout << turn[0] << " " << turn[1] << " " << turn[2] << "\n";
    int pos = (turn[jugador] * pasos) % size;
    if (pos) {
        if (tablero[pos] == -1)
            tablero[pos] = jugador;
        else {
            if (tablero[pos] != jugador) {
                return cnt + 1;
            }
        }
    }
    cnt++;
    return -1;
}

int main() {
    optimizar_io
 	int n, a, b, c; 
    ll inf = 3e9;

 	cin >> n >> a >> b >> c;
    tablero.assign(n + 1, -1);
    int cnt = 0, t;
    while (cnt <= 3 * (n + 1)) {
        t = turno(0, a, n + 1, cnt);
        if (t != -1) {
            cout << t << "\n";
            return 0;
        }
        t = turno(1, b, n + 1, cnt);
        if (t != -1) {
            cout << t << "\n";
            return 0;
        }
        t = turno(2, c, n + 1, cnt);
        if (t != -1) {
            cout << t << "\n";
            return 0;
        }
    }
    cout << inf << "\n";
    return 0;
}
