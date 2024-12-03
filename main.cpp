#include <iostream>
#include <cmath>
#include "solutionequation.hpp"
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
	
	solutioneq(a, b, c);

	return 0;
}