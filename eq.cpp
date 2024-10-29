#include <iostream>
#include <cmath>
using namespace std;

int main() {
	setlocale(LC_ALL, "Ru");

	double a,b,c,d,x1,x2;
	cout << "Введите a\n";
	cin >> a;
	cout << "Введите b\n";
	cin >> b;
	cout << "Введите c\n";
	cin >> c;

	d = b * b - 4 * a * c;
	if (d > 0) {
		x1 = ((-b) + sqrt(d)) / (2 * a);
		x2 = ((-b) - sqrt(d)) / (2 * a);
		cout << "Первый корень = " << x1 << "\n";
		cout << "Второй корень = " << x2 << "\n";
	}
	else if (d == 0) {
		x1 = ((-b) / 2 * a);
		cout << "Первый корень = " << x1 << "\n";
		cout << "Второй корень = " << x1 << "\n";
	}
	else if (d < 0) {
		cout << "Корней нет";
	}




	return 0;
}