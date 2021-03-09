#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;
map<char,char> mp;
int h, m;

int stringToInt(string &s) {
	stringstream ss(s);
	int res = 0;
	ss >> res;
	return res;
}

string intToStr(int x) {
	stringstream ss;
	ss << x;
	string str = ss.str();
	while (str.size() != 2) str.insert(0, "0");
	return str;
}

bool isValid(string horas, string minutos) {
	for (int i = 0; i < horas.size(); i++) {
		if (!mp.count(horas[i]))	
			return false;
		else
			horas[i] = mp[horas[i]];
	}
	for (int i = 0; i < minutos.size(); i++) {
		if (!mp.count(minutos[i]))	
			return false;
		else
			minutos[i] = mp[minutos[i]];
	}
	swap(horas, minutos);
	reverse(horas.begin(), horas.end());
	reverse(minutos.begin(), minutos.end());
	return (stringToInt(horas) < h and stringToInt(minutos) < m);
}

int main() {
	optimizar_io
    int tc;
	string s;

	mp['0'] = '0';
	mp['1'] = '1';
	mp['2'] = '5';
	mp['5'] = '2';
	mp['8'] = '8';

	cin >> tc;
	while (tc--) {
		cin >> h >> m >> s;
		int i;
		string horas;
		for (i = 0; s[i] != ':'; i++) {
			horas.push_back(s[i]);
		}
		string minutos;
		for (int j = i + 1; j < s.size(); j++) {
			minutos.push_back(s[j]);
		}
		while (!isValid(horas, minutos)) {
			int horas1 = stringToInt(horas), minutos1 = stringToInt(minutos);
			minutos1++;
			minutos1 %= m;
			if (minutos1 == 0) {
				horas1++;
				horas1 %= h;
			}
			horas = intToStr(horas1);
			minutos = intToStr(minutos1);
			// cout << horas << " " << minutos << "\n";
		}
		cout << horas << ":" << minutos << "\n";
	}
	return 0;
}
