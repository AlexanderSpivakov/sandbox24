#include <iostream>
#include <cmath>
using namespace std;

int solutioneq(double a, double b, double c) {
	double  d, x1, x2;
	d = (b * b) - (4 * a * c);
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