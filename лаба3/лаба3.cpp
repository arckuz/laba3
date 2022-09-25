#include <iostream>
#include <math.h>
#include <locale.h>
#include <string>
using namespace std;

void t1() {
	float y = 0;
	cout << "Таблица значений для функции: " << endl;
	cout << "x   y" << endl;
	for (int x = -7; x <= 3; x++)
	{
		if (-7 <= x && x <= -6) {
			y = -1;
		}
		else if (-6 < x && x <= -4) {
			y = -0.5 * (x + 4);
		}
		else if (-4 < x && x <= 0) {
			y = sqrt(4 - ((x + 2) * (x + 2)));
		}
		else if (0 < x && x <= 2) {
			y = -sqrt(1 - (x - 1) * (x - 1));
		}
		else if (2 < x && x <= 3) {
			y = -x + 2;
		}
		cout << x << "  " << y << endl;
	}

}
int t2_2(int a, int x, int p, int t) {
	int t0 = a % p;
	t = a % p;
	a = t * t0;
	x--;
	if (x == 0) {
		return a;
	}
	return t2_2(a, x, p, t);
}
int t2(int a, int x, int p) {
	//cin >> a >> x >> p;
	int t, t0;
	t = 0;
	t0 = a % p;
	for (int k = 1; k <= x; ++k) {
		t = a % p;
		a = t * t0;
	}
	//cout << t << endl;
	return t;
}
void t3() {
	 int b = 1234, a = 54;
	 while (b != 0) {
		 a %= b;
		 swap(a, b);
	 }
	 cout << "НОД = " << a;
 }
int t4(int b, int a) {
	int x = 1, y = 0, x1 = 0, y1 = 1, x2 = 0, y2 = 0, q = 0, r = 1,a1;
	a1 = a;
	//cout << b << "^-1 mod " << a << endl;
	while (r != 0) {
		q = a / b;
		r = a % b;
		x2 = x - q * x1;
		y2 = y - q * y1;
		x = x1;
		y = y1;
		x1 = x2;
		y1 = y2;
		a = b;
		b = r;
		//cout << "Остаток = " << r << " X = " << x2 << " Y = " << y2 << " Частные = " << q << endl;
	}
	if (y < 0) {
		y = y + a1;
	}
	//cout << "Взаимообратное число = " << y;
	return y;
}
void t7() {
	int a, b, c;
	cin >> a >> b >> c;
	int nom_stad = 0, ost = 0, b_mod = b % 4, a_mod = a % 10;
	if (a_mod == 0) cout << "Последняя цифра числа: 0";
	else if (a_mod == 1) cout << "последняя цифра числа: 1";
	else if (a_mod == 5) cout << "последняя цифра числа: 5";
	else if (a_mod == 6) cout << "последняя цифра числа: 6";
	else {
		for (int i = 1; i <= c; i++) {
			nom_stad = b % 4;
			b = b_mod * nom_stad;
		}
		if (a % 2 == 0 && nom_stad == 0) {
			cout << "Последняя цифра числа равна: 6";
		}
		else if (a % 2 != 0 && nom_stad == 0) {
			cout << "Последняя цифра числа равна: 1";
		}
		else {
			for (int j = 1; j <= nom_stad; j++) {
				ost = a % 10;
				a = a_mod * ost;
			}
			cout << "Последняя цифра числа равна : " << ost;
		}
	}
}
void t5() {
	//int g = 769, n = 557, x = 543445, y = 7335;
	int g, n, x, y;
	cout << "введите просты числа g n ";
	cin >> g;
	cin >> n;
	cout << "Введите числа x и y ";
	cin >> x;
	cin >> y;
	int k1, k2, Y, X, z;
	k1 = t2(g, x, n);
	Y = t2(g, y, n);
	X = t2(Y, x, n);
	z = t4(y, (n - 1));
	//cout << k1 << endl;
	k2 = t2(X, z, n);
	//cout << k2 << endl;
	string s;
	cout << "Введите текст " << endl;
	cin.get();
	getline(cin, s);
	cout << endl;
	s += " ";
	cout << "Входная строка: " << s << endl;
	string str1, str2;
	for (int i = 0; i < s.length(); i++) {
		int t = s[i];
		str1 += (char)(t + k1);
	}
	cout << "Зашифрованная строка: " << str1 << endl;
	for (int i = 0; i < str1.length(); i++) {
		int t = str1[i];
		str2 += (char)(t - k2);
	}
	cout << "Расшифрованная строка: " << str2;
}
int main()
{
	
	int av, xv, pv;
	setlocale(LC_ALL, "Russian");
	cout << "Введите номер задания: ";
	int N;
	cin >> N;
	switch (N) {
	case 1:
		t1();
		break;
	case 2:
		cout << "Введите a,x,p:";
		cin >> av >> xv >> pv;
		cout<<t2(av,xv,pv);
		break;
	case 3:
		t3();
		break;
	case 4:
		cout << "Введите a,p:";
		cin >> av >> pv;
		t4(av,pv);
		break;
	case 5:
		t5();
		break;
	case 7:
		t7();
		break;
	}
}
